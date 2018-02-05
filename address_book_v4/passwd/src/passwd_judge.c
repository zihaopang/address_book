#include <stdio.h>

#include "/home/address_book/include/src/all.h"

Link head;

void passwd_judge(sqlite3 *db_passwd)
{
    int i;
    int nrow;
    int ncolumn;
    int log_flag;
    char *errmsg;
    char **result;
    int registe_flag;
    int name_flag = 0;
    int passwd_flag = 0;
    char name[MAX_SIZE];
    char order[MAX_SIZE];
    char passwd[MAX_SIZE];
    char sql[MAX_SIZE * 10];
    
    passwd_table();

    printf("\t\t\t\t\tLOG/REGISTE:\n\t\t\t\t\t");
    scanf("%s",order);
    //对输入命令进行判断
    log_flag = strcmp("LOG",order);
    registe_flag = strcmp("REGISTE",order);

    if(log_flag == 0 || registe_flag == 0)
    {
    //如果是登录命令，打开数据库，选择信息，让用户输入用户名和密码
	if(log_flag == 0)
	{
	    sqlite3_get_table(db_passwd,"select * from passwd;",&result,&nrow,&ncolumn,&errmsg);

	    printf("\t\t\t\t\tPlease enter user name:");
	    scanf("%s",name);

	    printf("\t\t\t\t\tPlease enter passwd:");
	    scanf("%s",passwd);
    //匹配数据库中的姓名和密码和输入的姓名和密码
	    for(i = 1; i <= nrow; i++)
	    {
		if(!strcmp(name,result[i * ncolumn + 0]))
		{
	            name_flag = 1;
		    break;
		}
	    }
	    
	    for(i = 1; i <= nrow; i++)
	    {
		if(!strcmp(passwd,result[i * ncolumn + 1]))
		{
	            passwd_flag = 1;
		    break;
		}
	    }
    //对匹配标志进行判断
	    if((passwd_flag == 1) && (name_flag == 1))
	    {
                printf("\t\t\t\t\tlog success,please waiting……\n");
		
		sleep(1);
		
		system("reset");

		creat_link(&head);

		write_in_line(&head);
                
		welcome(); 
    
                input_order();

		exit(1);
	    }
	    else
	    {
		printf("\t\t\t\t\tname or password error!Please input again!\n");

		sleep(1);

		system("reset");
                    
		passwd_judge(db_passwd);
            }	    
	}
    //如果是注册命令，让用户注册姓名和帐号，并存入数据库
	if(registe_flag == 0)
	{
            printf("\t\t\t\t\tPlease enter new user name:");
	    scanf("%s",name);

            printf("\t\t\t\t\tPlease enter new password:");
	    scanf("%s",passwd);
            
	    sprintf(sql,"insert into passwd(user_name,user_passwd) values('%s','%s');",name,passwd);
	   
	    sqlite3_exec(db_passwd,sql,NULL,NULL,&errmsg);

	    printf("\t\t\t\t\tregiste success!Please waiting……\n");

	    sleep(3);

	    system("reset");

            creat_link(&head);

            welcome(); 
    
            input_order();

            exit(1);
	}
    }
    else
    {
        printf("\t\t\t\t\tPlease input correct order!\n");

	sleep(2);

	system("reset");

	passwd_judge(db_passwd);
    }


}
