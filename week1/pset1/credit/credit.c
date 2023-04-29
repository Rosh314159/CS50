 #include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    long number = get_long("Number:");
    long mod = 0;
    int n;
    long divisor = 0;
    int dig = 0;
    long digit = 0;
    int sum1 = 0;
    int sum2 = 0;
    int type = 0;
    int num1 = 0;
    int num2 = 0;
    
    for (n = 0; mod != number; n++)
    {
        divisor = pow(10,n);
        mod = number % divisor;
    }
    
    int digits = n - 1;
    //printf("Digits: %i\n", digits);
    
    for (int i = 1; i<=digits; i++)
    {
        divisor = pow(10,i);
        digit = number % divisor;
        digit = digit / (pow(10,i-1));
        //printf("Digit: %ld\n", digit);
        //printf("i: %i\n", i);
        if(i==digits)
        {
            num1 = digit;
        }
        if(i == digits-1)
        {
            num2 = digit;
        }
        
        
        if (i % 2 == 0)
        {
            if (digit>=5)
            {
                int one = ((2 * digit) % 10);
                sum1 = sum1 + 1 + one;
            }
            else
            {
                sum1 = sum1 + (2 * digit);
            }
            //printf("sum1: %i\n", sum1);
        }
        else
        {
            sum2 = sum2 + digit;
        }
        
    }
    
    //printf("Sum1: %i\n", sum1);
    //printf("Sum2: %i\n", sum2);
    //printf("Num1: %i\n",num1);
    //printf("Num2:%i\n",num2);
    int total = sum1 + sum2;
    if (total % 10 != 0)
    {
        printf("INVALID\n");
    }
    
    else if((digits==16 && num1==4) || (digits==13 && num1==4))
        {
            printf("VISA\n");
        }
    else if((digits==15 && num1==3 && num2==4) || (digits==15 && num1==3 && num2==7))
        {
            printf("AMEX\n");
        }
    else if((digits==16 && num1==5) && (num2>=1 && num2<=5))
        {
            printf("MASTERCARD\n");
        }
    
    else 
    {
        printf("INVALID\n");
    }
}
