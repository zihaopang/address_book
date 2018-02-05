#include <stdio.h>

#include "/home/address_book/include/src/all.h"

void reset()
{
   char ch;
   
   while(1)
   {
       printf("\033[1;34mPlease enter 'q' or 'Q' to continue:\033[0m");
       
       //getchar();

      // ch = getchar();
       scanf(" %c",&ch);
   
       if(ch == 'q' || ch == 'Q')
       {
           system("reset");
           
	   break;
       }
       else
       {
           printf("\033[0;31mIncorrect order!Please input again!\033[0m\n");
       }
   }
           	   
   welcome();

   input_order();
}
