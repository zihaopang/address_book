#include "/home/address_book/all.h"

int display()
{
    int i;
    int num;
    char ch;
    extern int sockfd;
    extern struct infor person;

    person.flag = LIST;
    person.list_flag = 1;     

    write(sockfd,&person,sizeof(struct infor));

    read(sockfd,&person,sizeof(struct infor));
    
    num = person.list_row;
    
    person.list_flag = 0; 
       
    system("reset");
    
    while(1)
    {
        for(i = 1; i <= num; i++)
        {
	    person.list_column = i;
    
	    write(sockfd,&person,sizeof(struct infor));
        
	    read(sockfd,&person,sizeof(struct infor));

            printf("ID:%d\n",person.id);
	    printf("NAME:%s\n",person.name);
	    printf("TEL:%s\n",person.tel);
	    printf("ADDR:%s\n",person.addr);
            printf("---------------------\n");
        }

       printf("\033[1;34mAny key to continue,enter 'q' or 'Q' to go back:\033[0m");
       
       scanf(" %c",&ch);

       if(ch == 'q' || ch == 'Q')
       {
           break;
       }
    }

    return 0;
}
