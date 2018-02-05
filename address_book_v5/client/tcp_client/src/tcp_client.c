#include "/home/address_book/all.h"

int sockfd;

struct infor person;

int main(int argc, char *argv[]) 
{ 
	struct sockaddr_in server_addr; 
        /**/
	if(argc!=2) 
	{ 
		fprintf(stderr,"Usage:%s hostname \a\n",argv[0]); 
		exit(1); 
	} 


	/**/ 
	if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1) //
	{ 
		fprintf(stderr,"Socket Error:%s\a\n",strerror(errno)); 
		exit(1); 
	} 

	/**/ 
	bzero(&server_addr,sizeof(server_addr)); //
	server_addr.sin_family=AF_INET;          // IPV4
	server_addr.sin_port=htons(portnumber);  //
	server_addr.sin_addr.s_addr=inet_addr(argv[1]);  //
	/**/ 
	if(connect(sockfd,(struct sockaddr *)(&server_addr),sizeof(struct sockaddr))==-1) 
	{ 
		fprintf(stderr,"Connect Error:%s\a\n",strerror(errno)); 
		exit(1); 
	} 

	
	while(1)
	{
            //显示登录界面，提示输入命令.
	    system("reset");
	    while(1)
	    {
	        passwd_table();
                
		passwd_judge();
		
		write(sockfd,&person,sizeof(struct infor));
		
		read(sockfd,&person,sizeof(struct infor));
		
		switch(person.flag)
		{
		    case LOG_SUCCESS:
		    {
                        printf("\t\t\t\t\tLog success!Please waiting……\n\t\t\t\t\t");
                        
			sleep(1);
                        
			system("reset");

                        welcome();

			input_order();
                        
			break;
		    }
		    case LOG_FAIL:
		    {
		        printf("\t\t\t\t\tThe name or passwd is incorrect!\n");
			
			sleep(3);

			system("reset");
			
			break;
		    }
		    case LOGIN_SUCCESS:
		    {
		        printf("\t\t\t\t\tLogin success ,please waiting……\n");

			sleep(1);
			
			system("reset");
                        
			welcome();

			input_order();

			break;
		    }
		    case LOGIN_FAIL:
		    {
		        printf("\t\t\t\t\tLogin fail!The name has been occupied!\n");
                        
			sleep(1);

			system("reset");

			break;
		    }
		}
	    }



	}
    
    close(sockfd); 
    exit(0); 
} 
