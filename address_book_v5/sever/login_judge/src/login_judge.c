#include "/home/address_book/all.h"

int login_judge(sqlite3 *passwd_db,int new_fd)
{
    int nrow;
    int ncolumn;
    char *errmsg;
    char **result;
    char sql[MAX_SIZE * 10];
    extern struct infor person;
    
    sprintf(sql,"select * from passwd where user_name='%s';",person.user_name);
    sqlite3_get_table(passwd_db,sql,&result,&nrow,&ncolumn,&errmsg);
    
    memset(sql,0,sizeof(sql)); 
    
    if(nrow == 0)
    {
        sprintf(sql,"insert into passwd(user_name,user_passwd) values('%s','%s');",person.user_name,person.user_passwd);
        
	sqlite3_exec(passwd_db,sql,NULL,NULL,&errmsg);

        person.flag = LOGIN_SUCCESS;
    }
    else
    {
        person.flag = LOGIN_FAIL;   
    }
    
    return 0;
}
