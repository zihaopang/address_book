#include "/home/address_book/all.h"

int search_judge(sqlite3 *save_db,int new_fd)
{
    int nrow;
    int ncolumn;
    char *errmsg;
    char **result;
    char sql[MAX_SIZE * 10];
    extern struct infor person;
    printf("name=%s\n",person.name); 
    sprintf(sql,"select * from save_infor where name='%s';",person.name);
        
    sqlite3_get_table(save_db,sql,&result,&nrow,&ncolumn,&errmsg);
    printf("row=%d\n",nrow); 
    printf("column=%d\n",ncolumn);
    if(person.search_flag == 1)
    {
	person.search_row = nrow;
    }
    else
    {
	person.id = *result[ncolumn * person.search_row + 0] - '0';
	strcpy(person.name,result[ncolumn * person.search_row + 1]);
	strcpy(person.tel,result[ncolumn * person.search_row + 2]);
	strcpy(person.addr,result[ncolumn * person.search_row + 3]);
    }

    return 0;
}
