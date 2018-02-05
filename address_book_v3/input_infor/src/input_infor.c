#include <stdio.h>
#include <stdlib.h>

#include "/home/address_book/include/src/all.h"

void input_infor()
{    
    char ch;
    
    extern Link head;
    
    while(1)
    {
	system("reset");

	printf("\033[0;34mInput 'q' or 'Q' to go back,press 'ENTER' to continue\033[0m\n");

	getchar();

	ch = getchar();
        
	if(ch == 'q' || ch == 'Q')
	{
            system("reset");

	    break;
	}
	else if(ch == '\n')
	{
	    Link newnode = (Link)malloc(sizeof(Infor));
        
	    if(newnode == NULL)
	    {
	        printf("malloc error!");
		exit(1);
	    }

	    printf("Please input id:");
            scanf("%s",newnode->id);
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
	}
	else
	{ 
	    printf("\033[0;31mIncorrect order!Please input again!\033[0m\n");
            
	    sleep(3);

	    input_infor();
	}
    }

   welcome();

   input_order();
}
