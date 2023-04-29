#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int key;
//string shift(string plaintext);
int main(int argc, string argv[])
{    
    string ciphertext;
    if (argc == 2)
    {
        
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (isalpha(argv[1][i]))
            {
                printf("Usage ./caesar key\n");
                i = n;
                return 1 ; //returns error if key is not a digit
            }
        }
        key = atoi(argv[1]); //converts key from string to integer
        printf("Key: %i\n", key);
    }

    else 
    {
        printf("Usage: ./caesar key\n");
        return 1 ;
    }
    
    string plaintext = get_string("Plaintext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                int a = plaintext[i] - 65; //converts uppercase ascii to alphabetical index
                int b = (a + key) % 26; //shifts by the key
                int c = b + 65; //converts back to ascii
                plaintext[i] = c;
            }
            else if (islower(plaintext[i]))
            {
                int a = plaintext[i] - 97; //converts lowercase ascii to alphabetical index
                int b = (a + key) % 26; //shifts by the key
                int c = b + 97; //converts back to ascii
                plaintext[i] = c;
            }
        }
}
printf("Ciphertext: %s\n", plaintext);
}