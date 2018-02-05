#include <stdio.h>
#include "/home//address_book/include/src/all.h"

void display_link(Link *head)
{
    int i = 1;
    char flag = 'a' - 1;
    Link temp = (*head)->next;
    
    if((*head)->next == *head)
    {
        system("reset");
	
	printf("none person!\n");

	reset();
    }
    
    while(flag <= 'z')
    {
        flag = flag + i;
	
	while(temp != *head)
        { 
	    if(flag == *(temp->name))
	    {
	        printf("ID:%d\n",temp->id);
	        printf("NAME:%s\n",temp->name);
	        printf("TELEPHONE NUMBER:%s\n",temp->tele);
	        printf("ADDRESS:%s\n",temp->address);
                printf("************************\n");
		
		printf("\n");
            }

	    temp = temp->next;

        }
        
	temp = (*head)->next;
    }
     
    reset();
}
