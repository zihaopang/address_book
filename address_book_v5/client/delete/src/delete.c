#include "/home/address_book/all.h"

int delete_infor()
{
    int i;
    int id;
    int row;
    int column;
    extern int sockfd;
    extern struct infor person;
    struct infor infor[MAX_SIZE];
    
    person.flag = DELETE;

    system("reset");

    printf("Please enter person's name you want to delete:");
    scanf("%s",person.name);

    person.delete_flag = 0;
    
    write(sockfd,&person,sizeof(struct infor));
    
    read(sockfd,&person,sizeof(struct infor));

    row = person.delete_row;
    column = person.delete_column;
    
    person.delete_flag = 1;

    for(i = 1; i <= row; i++)
    {
        person.delete_column = i;

	write(sockfd,&person,sizeof(struct infor));
	
	read(sockfd,&person,sizeof(struct infor));

	infor[i - 1].id = person.id;
	strcpy(infor[i - 1].name,person.name);
	strcpy(infor[i - 1].tel,person.tel);
	strcpy(infor[i - 1].addr,person.addr);
    }
    
    if(row > 1)
    {
        system("reset");
	
	for(i = 0; i < row; i++)
	{
	    printf("ID:%d\n",infor[i].id);
	    printf("NAME:%s\n",infor[i].name);
	    printf("TEL:%s\n",infor[i].tel);
	    printf("ADDR:%s\n",infor[i].addr);
	    printf("-------------------------\n");
	}

	person.delete_flag = 2;

	printf("There are %d people you have this name,please input id to delete:",row);
        scanf("%d",&id);
        
        person.delete_num = id;

	write(sockfd,&person,sizeof(struct infor));
	
	read(sockfd,&person,sizeof(struct infor));

	if(person.flag == DELETE_SUCCESS)
	{
	    printf("Delete success!\n");
	    sleep(1);
	}
	else
	{
	    printf("Delete fail!\n");
	    sleep(1);
	}
    }
    else
    {
        person.delete_num = infor[0].id;
	
	person.delete_flag = 2;
	
	write(sockfd,&person,sizeof(struct infor));
	
	read(sockfd,&person,sizeof(struct infor));

	if(person.flag == DELETE_SUCCESS)
	{
	    printf("Delete success!\n");
	    sleep(1);
	}
	else
	{
	    printf("Delete fail!\n");
	    sleep(1);
	}
    }

    return 0;
}
