#include "/home/address_book/all.h"

int search()
{
    int i;
    int row;
    extern int sockfd;
    extern struct infor person;

    system("reset");
    
    printf("Please enter the person's name you want search:");
    scanf("%s",person.name);

    person.flag = SEARCH;
    person.search_flag = 1; 
    
    write(sockfd,&person,sizeof(struct infor));
    
    read(sockfd,&person,sizeof(struct infor));
    
    row = person.search_row;

    if(row == 0)
    {
        printf("none person!\n");
    }
    else
    {
        for(i = 1; i <= row; i++)
        {
            person.search_flag = 2;
	    person.search_row = i;
        
	    write(sockfd,&person,sizeof(struct infor));
            read(sockfd,&person,sizeof(struct infor));
        
            printf("ID:%d\n",person.id);
	    printf("NAME:%s\n",person.name);
	    printf("TEL:%s\n",person.tel);
            printf("ADDR:%s\n",person.addr);
	    printf("----------------------\n");
        }
    }
    
    reset();
    
    return 0;
}
