#include <stdio.h>

#include "voice.h"

void reset()
{
   char ch;;
   
   while(1)
   {
       printf("Please enter 'q' or 'Q' to continue:\n");
       
       getchar();

       ch = getchar();
   
       if(ch == 'q' || ch == 'Q')
       {
           system("reset");
           
	   break;
       }
       else
       {
           printf("Incorrect order!Please input again!\n");
       }
   }
           	   
   welcome();

   input_order();
}
