#include "/home/address_book/all.h"

int insert()
{
    extern int sockfd;
    extern struct infor person;
    
    system("reset");
    
    while(1)
    {
        reset();
    
        person.flag = INSERT;
    
        printf("Please enter id:");
        scanf("%d",&person.id);
    
        printf("Please enter name:");
        scanf("%s",person.name);
	
        printf("Please enter tel:");
        scanf("%s",person.tel);
    
        printf("Please enter addr:");
        scanf("%s",person.addr);
       

        write(sockfd,&person,sizeof(struct infor));
                
        read(sockfd,&person,sizeof(struct infor));
        
        if(person.flag == INSERT_SUCCESS)
        {
	    printf("Insert success!\n");
	    sleep(1);
        }
        else
        {
	    printf("Insert fail!Id %d has been occupied!\n",person.id);
	    sleep(1);
        }
    }

    return 0;
}
