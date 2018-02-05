#include <stdio.h>
#define MAX_SIZE 100

#include "voice.h"

int main()
{
    system("reset");
    
    welcome(); 
    
    Link head;
    creat_link(&head);
    
    input_order();
    
    
    return 0;
}
