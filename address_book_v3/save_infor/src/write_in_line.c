#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/fcntl.h>

#include "/home/address_book/include/src/all.h"

int read_line(int fd,char *buf,int max_len)
{
    int i;
    int ret;
    char temp;
    
    for(i = 0; i < max_len; i++)
    {
        ret = read(fd,&temp,1);
	
	if(ret == -1)
	{
	    perror("read error!");

	    exit(1);
	}
        
	if(ret == 0)
	{
	    break;
	}

	if((temp == ':') || (temp == '\n'))
	{
	    break;
	}
	
	buf[i] = temp;
    }
    
    buf[i] = '\0';
    
    return i;

}

void write_in_line()
{
    int o_fd;
    int flag = 1;
    extern Link head;
    char buf[MAX_SIZE];
   
    o_fd = open("/home/address_book/save_infor.txt",O_RDWR | O_CREAT,0655);
    
    Link newnode = (Link)malloc(sizeof(Infor));
    
    while(read_line(o_fd,buf,sizeof(buf)))
    {
	switch(flag)
	{
	    case 1:
	    {
	        strcpy(newnode->id,buf);
		
		break;
	    }
	    case 2:
	    {
	        strcpy(newnode->name,buf);

		break;
	    }
            case 3:
	    {
	        strcpy(newnode->tele,buf);

		break;
	    }
	    case 4:
	    {
	        strcpy(newnode->address,buf);
		
	        flag = 0;
	    
		insert_tail_node(&head,&newnode);

	        newnode = (Link)malloc(sizeof(Infor));
		
		break;
	    }
	    default:
	    {
	        printf("error!");

		break;
	    }
        }

	flag++;
	
	memset(buf,0,sizeof(buf));
    }
    
    close(o_fd);
    
}
