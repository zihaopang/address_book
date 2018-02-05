#include "/home/address_book/all.h"

int insert_judge(sqlite3 *save_db,int new_fd) 
{
    int nrow;
    int ncolumn;
    char *errmsg;
    char **result;
    char sql[MAX_SIZE * 10];
    extern struct infor person;
    
    sprintf(sql,"select * from save_infor where id=%d;",person.id);
    
    sqlite3_get_table(save_db,sql,&result,&nrow,&ncolumn,&errmsg);
    
    
    if(nrow > 0)
    {
	person.flag = INSERT_FAIL;
    }
    else
    {
        sprintf(sql,"insert into save_infor(id,name,tel,addr) values(%d,'%s','%s','%s');",BASIC_INFOR); 
        
	sqlite3_exec(save_db,sql,NULL,NULL,&errmsg);

	person.flag = INSERT_SUCCESS;
    }


    return 0;
}
