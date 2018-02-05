#include "/home/address_book/all.h"

struct infor person;

int main(int argc, char *argv[]) 
{ 
	int opt;
	int r_len;
	char *errmsg;
	int sin_size;
        sqlite3 *save_db;
	int sockfd,new_fd; 
	sqlite3 *passwd_db;
	struct sockaddr_in server_addr; 
	struct sockaddr_in client_addr;
	/**/ 
	if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1) // AF_INET:IPV4;SOCK_STREAM:TCP
	{ 
		fprintf(stderr,"Socket error:%s\n\a",strerror(errno)); 
		exit(1); 
	} 

	/**/ 
	bzero(&server_addr,sizeof(struct sockaddr_in)); //
	server_addr.sin_family=AF_INET;                 // Internet
//	server_addr.sin_addr.s_addr=htonl(INADDR_ANY);  // 
	server_addr.sin_addr.s_addr=inet_addr("192.168.1.120");  //
	server_addr.sin_port=htons(portnumber);         // 
        setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));	
	/**/ 
	if(bind(sockfd,(struct sockaddr *)(&server_addr),sizeof(struct sockaddr))==-1) 
	{ 
		fprintf(stderr,"Bind error:%s\n\a",strerror(errno)); 
		exit(1); 
	} 

	/**/ 
	if(listen(sockfd,5)==-1) 
	{ 
		fprintf(stderr,"Listen error:%s\n\a",strerror(errno)); 
		exit(1); 
	} 
        //打开或创建密码、信息保存数据库
        
	sqlite3_open(INFOR_PATH,&save_db);
        sqlite3_exec(save_db,"create table save_infor(id integer,name text,tel text,addr text);",NULL,NULL,&errmsg);
	
	sqlite3_open(PASSWD_PATH,&passwd_db);
        sqlite3_exec(passwd_db,"create table passwd(user_name text,user_passwd text);",NULL,NULL,&errmsg);
	

	while(1) 
	{ 
		sin_size=sizeof(struct sockaddr_in); 
		
		if((new_fd=accept(sockfd,(struct sockaddr *)(&client_addr),&sin_size))==-1) 
		{ 
			fprintf(stderr,"Accept error:%s\n\a",strerror(errno)); 
			exit(1); 
		}

		fprintf(stderr,"Server get connection from %s\n",inet_ntoa(client_addr.sin_addr)); 
                
		while(1)
                {
		    memset(&person,0,sizeof(struct infor));

		    while((r_len = read(new_fd,&person,sizeof(struct infor))) < 0)
		    {
		        perror("read error!");

		        exit(1);
		    }

		    if(r_len == 0)
		    {
		        printf("The client is closed!\n");

			break;
		    }
		    
		    switch(person.flag)
		    {
		        case LOGIN:
		        {
		            login_judge(passwd_db,new_fd);

			    break;
		        }
		        
			case LOG:
		        {
		            log_judge(passwd_db,new_fd);

			    break;
		        }

			case INSERT:
			{
			    insert_judge(save_db,new_fd);

			    break;
			}

			case LIST:
			{
			    display_judge(save_db,new_fd);

			    break;
			}

			case DELETE:
                        {
			    delete_judge(save_db,new_fd);

			    break;
			}
			case SEARCH:
			{
			    search_judge(save_db,new_fd);

			    break;
			}
		    }
                    
		    write(new_fd,&person,sizeof(struct infor));

	        }

		close(new_fd);
	} 
	
	close(sockfd); 
	exit(0); 
} 
