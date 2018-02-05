#include "/home/address_book/all.h"

int delete_judge(sqlite3 *save_db,int new_fd)
{
    int nrow;
    int ncolumn;
    char *errmsg;
    char **result;
    char sql[MAX_SIZE * 10];
    extern struct infor person;

    if(person.delete_flag == 0)
    {
	sprintf(sql,"select * from save_infor where name='%s';",person.name);

	sqlite3_get_table(save_db,sql,&result,&nrow,&ncolumn,&errmsg);
	
	person.delete_row = nrow;
	person.delete_column = ncolumn;
    }
    else if(person.delete_flag == 1)
    {
	sprintf(sql,"select * from save_infor where name='%s';",person.name);

	sqlite3_get_table(save_db,sql,&result,&nrow,&ncolumn,&errmsg);
	
        person.id = *result[ncolumn * person.delete_column + 0] - '0';
	strcpy(person.name,result[ncolumn * person.delete_column + 1]);
	strcpy(person.tel,result[ncolumn * person.delete_column + 2]);
	strcpy(person.addr,result[ncolumn * person.delete_column + 3]);
    }
    else
    {
	sprintf(sql,"delete from save_infor where id=%d;",person.delete_num);
	
        if(sqlite3_exec(save_db,sql,NULL,NULL,&errmsg))
	{
	    person.flag = DELETE_FAIL;
	}
	else
	{
	    person.flag = DELETE_SUCCESS;
	}
    }

    return 0;

}
