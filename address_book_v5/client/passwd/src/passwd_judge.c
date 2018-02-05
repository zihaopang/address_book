#include "/home/address_book/all.h"

int passwd_judge()
{
    char order[MAX_SIZE];
    extern struct infor person;

    printf("\t\t\t\t\tLOG/LOGIN:\n\t\t\t\t\t");
    scanf("%s",order);
    
    if(!strcmp(order,"LOGIN"))
    {
        person.flag = LOGIN;

	printf("\t\t\t\t\tPlease input new user name:\n\t\t\t\t\t");
        scanf("%s",person.user_name);

	printf("\t\t\t\t\tPlease input new passwd:\n\t\t\t\t\t");
	scanf("%s",person.user_passwd);
    }
    else if(!strcmp(order,"LOG"))
    {
        person.flag = LOG;

	printf("\t\t\t\t\tPlease input user name:\n\t\t\t\t\t");
        scanf("%s",person.user_name);

	printf("\t\t\t\t\tPlease input passwd:\n\t\t\t\t\t");
	scanf("%s",person.user_passwd);
    }
    else
    {
        system("reset");
        
        passwd_table();

	printf("\t\t\t\t\tIncorrect order!Please input again!\n");

	passwd_judge();
    }
    
    return 0;
}
