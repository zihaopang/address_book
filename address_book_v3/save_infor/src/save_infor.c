#include <stdio.h>

#include "/home/address_book/include/src/all.h"

void save_infor(Link *head,FILE *stream)
{
    char ch;
    Link temp = (*head)->next;
    
    printf("\t\t\tDo you want to save the imformation?(y/n):");
	    
    getchar();
    ch = getchar();
    
    if(ch == 'y')
    {
	while(temp != *head)
        {
            fprintf(stream,"%s:",temp->id);
            fprintf(stream,"%s:",temp->name);
            fprintf(stream,"%s:",temp->tele);
            fprintf(stream,"%s\n",temp->address);
            
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

       save_infor(head,stream);		
   }
    
    fclose(stream);
}
