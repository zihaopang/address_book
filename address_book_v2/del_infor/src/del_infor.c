#include <stdio.h>

#include "/home/address_book/include/src/all.h"


int del_infor(Link *head)
{
    int id;
    int flag = 1;
    int count_name = 0;
    char name[MAX_SIZE];

    if((*head)->next == *head)
    {
	system("reset");
        
	printf("none person!\n");

	sleep(3);

	system("reset");

	reset();

	return -1;
    }

    Link temp = (*head)->next;
    
    system("reset");

    printf("\033[1;34mPlease input people's name you want delete:\033[0m\n");
    scanf("%s",name);

    while(temp != *head)
    {
        if(strcmp(name,temp->name) == 0)
	{
	    count_name++;
	}

	temp = temp->next;
    }

    temp = (*head)->next; 
    
    if(count_name == 1)
    {
        if(strcmp(name,temp->name) == 0)
	{
	    temp->prior->next = temp->next;
	    temp->next->prior = temp->prior;
	    
	    free(temp);
	    temp = NULL;

	    printf("Delete success!\n");
	    
	    reset();

	    return 0;
	}

	temp = temp->next;
    }
    else if(count_name > 1)
    {
        system("reset");

	while(temp != *head)
	{   
            if(strcmp(name,temp->name) == 0)
	    {
	        printf("ID:%d\n",temp->id);
	        printf("NAME:%s\n",temp->name);
	        printf("TELEPHONE NUMBER:%s\n",temp->tele);
	        printf("ADDRESS:%s\n",temp->address);
		printf("**********************\n");

		printf("\n");
	    }

	    temp = temp->next;
	}

        temp = (*head)->next; 
	
	printf("Please input person's ID you want delete!\n");
        scanf("%d",&id);

	while(temp != *head)
        {
            if(temp->id == id)
	    {
	        temp->prior->next = temp->next;
	        temp->next->prior = temp->prior;

	        free(temp);
	        temp = NULL;

	        flag = 0;

	        printf("Delete success!\n");
	        
		reset();
	        return 0;
	    }

	    temp = temp->next;
        }
    }
    else
    {
        printf("no information!\n");
	reset();
    }

    reset();

    return 0;
}
