#include <stdio.h>
#define MAX_SIZE 100

#include "/home/address_book/include/src/all.h"

FILE *fp;

int main()
{
    system("reset");
 
    fp = fopen("/home/address_book/passwd.txt","a+");
    
    passwd_judge(fp);
    
    return 0;
}
