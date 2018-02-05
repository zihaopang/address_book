#include <stdio.h>
#include <stdlib.h>

#include "/home/address_book/include/src/all.h"

void input_order()
{
    FILE *stream;
    char order[MAX_SIZE];
    
    stream = fopen("/home/address_book/save_infor.txt","w+");

    printf("\t\t\t\033[1;34mINSERT/LIST/SEARCH/DELETE/QUIT:\033[0m");
    scanf("%s",order);

    int flag_insert = strcmp("INSERT",order);
    int flag_list = strcmp("LIST",order);
    int flag_search = strcmp("SEARCH",order);
    int flag_delete = strcmp("DELETE",order);
    int flag_quit = strcmp("QUIT",order);
    

    if(flag_insert == 0 || flag_list == 0 || flag_search == 0 || flag_delete == 0 || flag_quit == 0)
    {
        if(flag_insert == 0)
	{
	    input_infor();
	}
	
	if(flag_list == 0)
	{ 
	    system("reset");

	    extern Link head;
	   
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

	if(flag_quit == 0)
	{
	    extern Link head;
	
	    save_infor(&head,stream);
	}

    }
    else
    {
        system("reset");
	welcome();
	printf("\033[0;31mThe order is incorrect!Please input again!How operate please read the instructions.\033[0m\n ");
	input_order();
    }
}
