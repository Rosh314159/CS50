#include <cs50.h>
#include <stdio.h>

int main(void)
{   
    int i = 0;
    int n = 0;
    int end = 0;
    do 
     {
         n = get_int("Starting Population:");  // TODO: Prompt for start size
          
     }
      while(n<9);
      
     do 
     {
         end = get_int("End Population:"); // TODO: Prompt for end size
          
     }
     while (end < n);
      
      int difference = end - n;
      int net = 0;
     
      printf("n:%i\n",n);
      
      for (i = 0; n < end; i++)  // TODO: Calculate number of years until we reach threshold

     {
        n = n + (n / 3) - (n / 4);
          
     }
      
     printf("Years: %i\n", i); // TODO: Print number of years
      
      
}