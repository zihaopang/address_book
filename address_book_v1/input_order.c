#include <stdio.h>
#include <stdlib.h>

#include "voice.h"

void input_order()
{
    char order[MAX_SIZE];

    printf("INSERT/LIST/SEARCH/DELETE:");
    scanf("%s",order);

    int flag_insert = strcmp("INSERT",order);
    int flag_list = strcmp("LIST",order);
    int flag_search = strcmp("SEARCH",order);
    int flag_delete = strcmp("DELETE",order);
    

    if(flag_insert == 0 || flag_list == 0 || flag_search == 0 || flag_delete == 0)
    {
        if(flag_insert == 0)
	{
	    input_infor();
	}
	
	if(flag_list == 0)
	{
	    extern Link head;
            
	    system("reset");

	    display_link(&head);

	    reset();
	}

	if(flag_search == 0)
	{
	    extern Link head;

	    search_infor(&head);
	}

	if(flag_delete == 0)
	{
	    extern Link head;

	    del_infor(&head);
	}

    }
    else
    {
        system("reset");
	welcome();
	printf("The order is incorrect!Please input again!\n ");
	input_order();
    }
}
