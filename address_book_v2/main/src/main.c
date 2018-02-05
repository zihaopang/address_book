#include <stdio.h>
#define MAX_SIZE 100

#include "/home/address_book/include/src/all.h"

Link head;

int main()
{
    system("reset");
    
    creat_link(&head);

    welcome(); 
    
    Link head;
    creat_link(&head);
    
    input_order();
    
    
    return 0;
}
