#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    
    do
    {
        n = get_int("Height: "); //prompts user for height
    }
    while (n<1 || n>8); //assures number is between 1 and 8
    
    for (int i = 0; i < n; i++)
  {
      for (int j = n-1; j > i; j--)
      {
          printf(" "); //aligns each line
      }
      for (int j = -1; j < i; j++)
      {
          printf("#"); //for each new line number of # increases by 1
      }
      printf("\n"); //print new line
  }
    
}