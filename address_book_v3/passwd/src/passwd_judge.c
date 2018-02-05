#include <stdio.h>

#include "/home/address_book/include/src/all.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/fcntl.h>

Link head;

void passwd_judge(FILE *fp)
{
    int i = 0;
    int logo_flag;
    int registe_flag;
    char order[MAX_SIZE];
    static int count = 3;
    char user_passwd[MAX_SIZE];
    char passwd[MAX_SIZE];
    
    passwd_table();
    
    printf("\t\t\t\t\tLOGO/REGISTE\n\t\t\t\t\t");
    scanf("%s",order);
    
    logo_flag = strcmp("LOGO",order);
    registe_flag = strcmp("REGISTE",order);

    if(logo_flag == 0 || registe_flag == 0)
    {   
        if(logo_flag == 0)
	{
            printf("\t\t\t\t\tPlease enter passwd:");
            scanf("%s",passwd);
            
            while(!feof(fp))
	    {
	        fgets(user_passwd,sizeof(user_passwd),fp);
		
		i = 0;

	        while(passwd[i] != '\0')
	        {
	            if(passwd[i] == user_passwd[i])
		    {
		        i++;
		    }
		    else
		    {
			memset(user_passwd,0,sizeof(user_passwd));
			break;
		    }
	        }
		
		if((strlen(user_passwd) - 1) == i)
		{
		    break;
		}
	    }
	    
	    if((strlen(user_passwd) - 1) == i)
	    {
	        printf("\t\t\t\t\tlog success!Please waiting……\n");
                
		sleep(2);

		system("reset");

                creat_link(&head);
            
	        write_in_line(&head);
    
                welcome(); 
    
                input_order();

		exit(1);

	    }
	    else
	    {
	        
                while(1)
	        {
		    printf("\t\t\t\t\tPassword error!You have %d times left!\n",count);
		    
		    sleep(2);

		    system("reset");
	            
		    count--;
		    
		    if(count < 0)
		    {
		        break;
		    }

		    fseek(fp,0,SEEK_SET);
		    
		    passwd_judge(fp);
		    
                }
             
	        exit(1);
	    }
        }

	if(registe_flag == 0)
	{
	    printf("\t\t\t\t\tPlease enter new password:");
	    scanf("%s",user_passwd);

            fwrite(user_passwd,strlen(user_passwd),1,fp);
            
	    fclose(fp);
	    
	    system("reset");
	    
	    write_in_line(&head);
    
            welcome(); 
    
            input_order();

            exit(1);
	}
    }
    else
    {
        printf("\t\t\t\t\tPlease input the correct order!\n");
        sleep(2);
	system("reset");

	fseek(fp,0,SEEK_SET);

	passwd_judge(fp);
    }
    
}
