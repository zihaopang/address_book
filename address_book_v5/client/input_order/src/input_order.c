#include "/home/address_book/all.h"

int input_order()
{
    char order[MAX_SIZE];

    printf("\t\t\t\t\tINSERT/LIST/DELETE/SEARCH/QUIT:\n\t\t\t\t\t");
    scanf("%s",order);
    
    
    if(!strcmp(order,"INSERT"))
    {
        insert();
	
	system("reset");
	welcome();
	input_order();
    }
    else if(!strcmp(order,"LIST"))
    {
        display();
	
	system("reset");
	welcome();
	input_order();
    }
    else if(!strcmp(order,"DELETE"))
    {
        delete_infor();
	
	system("reset");
	welcome();
	input_order();
    }
    else if(!strcmp(order,"SEARCH"))
    {
        search();
	
	system("reset");
	welcome();
	input_order();
    }
    else if(!strcmp(order,"QUIT"))
    {
        exit(1);
    }
    else
    {
        system("reset");

	welcome();
	
	printf("\t\t\t\t\tThe order is incorrect!Please try again!\n");

	input_order();
    }
    
    return 0;
}
