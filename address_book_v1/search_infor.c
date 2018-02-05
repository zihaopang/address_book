#include <stdio.h>

#include "voice.h"

void search_infor(Link *head)
{
    int id;
    int flag1 = 1;
    int flag2 = 1;
    char name[MAX_SIZE]; 
    Link temp = (*head)->next;
    
    system("reset");

    printf("Please enter the person's name you want search:");
    scanf("%s",name);
    
    while(temp != *head)
    {
        if(strcmp(name,temp->name) == 0)
	{
	    
	    printf("ID:%d\n",temp->id);
	    printf("NAME:%s\n",temp->name);
	    printf("TELEPHONE NUMBER:%s\n",temp->tele);
	    printf("ADDRESS:%s\n",temp->address);
            
            flag1 = 0;
            flag2++;
	}
	
	temp = temp->next;
    }
    
    if(flag2 > 2)
    {

	printf("Please enter the person's id you want search:\n");
        scanf("%d",&id);
         
	system("reset");
        
	Link temp = (*head)->next;
	
        while(temp != *head)
        {
            if(temp->id == id)
	    {
	        printf("ID:%d\n",temp->id);
	        printf("NAME:%s\n",temp->name);
	        printf("TELEPHONE NUMBER:%s\n",temp->tele);
	        printf("ADDRESS:%s\n",temp->address);
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
