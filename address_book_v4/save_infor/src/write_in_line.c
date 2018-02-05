#include <stdio.h>

#include "/home/address_book/include/src/all.h"

void write_in_line(Link *head)
{
    int i;
    int nrow;
    Link temp;
    int ncolumn;
    char *errmsg;
    char **result;
    sqlite3 *db_save;
    
    temp = (*head)->next;
    
    sqlite3_open("/home/address_book/save_infor.db",&db_save);

    sqlite3_get_table(db_save,"select * from save_infor;",&result,&nrow,&ncolumn,&errmsg);

    for(i = 1; i <= nrow; i++)
    {
        Link newnode = (Link)malloc(sizeof(Infor));
        
	newnode->id = *result[i * ncolumn + 0] - '0';
	strcpy(newnode->name,result[i * ncolumn + 1]);
	strcpy(newnode->tele,result[i * ncolumn + 2]);
	strcpy(newnode->address,result[i * ncolumn + 3]);

	insert_tail_node(head,&newnode);
    }
}
