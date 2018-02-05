#include <stdio.h>

#include "/home/address_book/include/src/all.h"

void search_infor(Link *head)
{
    int flag1 = 1;
    int flag2 = 1;
    char id[MAX_SIZE];
    char name[MAX_SIZE]; 
    Link temp = (*head)->next;
    
    system("reset");

    if((*head)->next == *head)
    {
        printf("\033[0;31mnone preson!\033[0m\n");

	reset();
    }

    printf("\033[1;34mPlease enter the person's name you want search:\033[0m");
    scanf("%s",name);
    
    while(temp != *head)
    {
        if(strcmp(name,temp->name) == 0)
	{
	    
	    printf("ID:%s\n",temp->id);
	    printf("NAME:%s\n",temp->name);
	    printf("TELEPHONE NUMBER:%s\n",temp->tele);
	    printf("ADDRESS:%s\n",temp->address);
	    printf("*********************\n");

	    printf("\n");
            
            flag1 = 0;
            flag2++;
	}
	
	temp = temp->next;
    }
    
    if(flag2 > 2)
    {

	printf("\033[1;34mPlease enter the person's id you want search\033[0m:\n");
        scanf("%s",id);
         
	system("reset");
        
	Link temp = (*head)->next;
	
        while(temp != *head)
        {
            if(strcmp(temp->id,id) == 0)
	    {
	        printf("ID:%s\n",temp->id);
	        printf("NAME:%s\n",temp->name);
	        printf("TELEPHONE NUMBER:%s\n",temp->tele);
	        printf("ADDRESS:%s\n",temp->address);
		printf("*********************\n");

		printf("\n");
            }

	    temp = temp->next;
        }
    }
 
    if(flag1 == 1)
    {
        printf("no information!\n");

	reset();
    }

    reset();
}
