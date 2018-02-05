#include <stdio.h>

#include "/home/address_book/include/src/all.h"

#define INFOR temp->id,temp->name,temp->tele,temp->address


void save_infor(Link *head)
{
    char ch;
    char *errmsg;
    sqlite3 *db_save;
    char sql[MAX_SIZE];
    Link temp = (*head)->next;
    printf("\t\t\tDo you want to save the imformation?(y/n):");
	    
    getchar();
    ch = getchar();
    
    if(ch == 'y')
    {
	sqlite3_open("/home/address_book/save_infor.db",&db_save);
	
	sqlite3_exec(db_save,"create table save_infor(id integer,name text,tele text,address text);",NULL,NULL,&errmsg);
        
	sqlite3_exec(db_save,"delete from save_infor;",NULL,NULL,&errmsg); 
        
	while(temp != *head)
	{
	    
	    sprintf(sql,"insert into save_infor(id,name,tele,address) values(%d,'%s','%s','%s');",INFOR);

	    sqlite3_exec(db_save,sql,NULL,NULL,&errmsg);
	    
	    temp = temp->next;
        }

        printf("\t\t\tsave success!\n");
        
	exit(1);
   }
   else if(ch == 'n')
   {
	exit(1);
   }
   else
   {
       printf("\t\t\tPlease enter n/y.\n");

       save_infor(head);		
   }
}
