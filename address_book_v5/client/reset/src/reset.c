#include "/home/address_book/all.h"

void reset()
{
   char ch;
   
   while(1)
   {

       printf("\033[1;34mAny key to continue,enter 'q' or 'Q' to go back:\033[0m");
       
       getchar();
       ch = getchar();
       //scanf(" %c",&ch);
   
       if(ch == 'q' || ch == 'Q')
       {
           system("reset");
           
	   welcome();
   
           input_order();

	   break;
       }
       else
       {
           break;
       }
   }
 
}
