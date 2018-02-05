#include "/home/address_book/all.h"

int display_judge(sqlite3 *save_db,int new_fd)
{
    int nrow;
    int ncolumn;
    char *errmsg;
    char **result;
    extern struct infor person;
    
    if(person.list_flag == 1)
    {
        sqlite3_get_table(save_db,"select * from save_infor;",&result,&nrow,&ncolumn,&errmsg);
	
	person.list_row = nrow;
    }
    else
    {
        sqlite3_get_table(save_db,"select * from save_infor order by name;",&result,&nrow,&ncolumn,&errmsg);

        person.id = *result[ncolumn * person.list_column + 0] - '0';
	strcpy(person.name,result[ncolumn * person.list_column + 1]);
	strcpy(person.tel,result[ncolumn * person.list_column + 2]);
	strcpy(person.addr,result[ncolumn * person.list_column + 3]);

    }

    return 0;

}
