#include "/home/address_book/all.h"

int log_judge(sqlite3 *passwd_db,int new_fd)
{
    int nrow;
    int ncolumn;
    char *errmsg;
    char **result;
    char sql[MAX_SIZE * 10];
    extern struct infor person;
   
    sprintf(sql,"select * from passwd where user_name='%s'",person.user_name);
    
    sqlite3_get_table(passwd_db,sql,&result,&nrow,&ncolumn,&errmsg);
    
    if(strcmp(result[ncolumn + 1],person.user_passwd) == 0)
    {
        person.flag = LOG_SUCCESS;
    }
    else
    {
        person.flag = LOG_FAIL;
    }

    return 0;
}    

