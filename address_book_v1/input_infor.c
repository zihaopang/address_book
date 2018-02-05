#include <stdio.h>
#include <stdlib.h>

#include "voice.h"

Link head;

void input_infor()
{    
    char ch;
    
    static int flag = 1;
    
    if(flag)
    {
	creat_link(&head);
	flag = 0;
    }
        
    while(1)
    {
	system("reset");

	printf("Input 'q' or 'Q' to go back,anykey continue\n");

	getchar();

	ch = getchar();

	if(ch == 'q' || ch == 'Q')
	{
            system("reset");

	    break;
	}
	else
	{
	    Link newnode = (Link)malloc(sizeof(Infor));
        
	    if(newnode == NULL)
	    {
	        printf("malloc error!");
		exit(1);
	    }

	    printf("Please input id:");
            scanf("%d",&newnode->id);
            printf("\n");

            printf("Please input name:");
            scanf("%s",newnode->name);
            printf("\n");

            printf("Please input telephone number:");
            scanf("%s",newnode->tele);
            printf("\n");

            printf("Please enter address:");
            scanf("%s",newnode->address);
            printf("\n");
                
            insert_tail_node(&head,&newnode);
            
	    system("reset");
	}
    }

   welcome();

   input_order();
}
