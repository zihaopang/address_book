#include <stdio.h>
#define MAX_SIZE 100

#include "/home/address_book/include/src/all.h"

#include <sqlite3.h>

int main()
{
    char *errmsg;
    int ret_passwd;
    sqlite3 *db_passwd;

    system("reset");
    
    ret_passwd = sqlite3_open("/home/address_book/passwd.db",&db_passwd);

    if(ret_passwd != SQLITE_OK)
    {
        printf("open/creat db error!\n");

	exit(1);
    }

    sqlite3_exec(db_passwd,"create table passwd(user_name text,user_passwd text);",NULL,NULL,&errmsg);
    
    passwd_judge(db_passwd);

    return 0;
}
