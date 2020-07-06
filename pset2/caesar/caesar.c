#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //check number command-line arguments
    if (argc == 2)
    {
        printf("Success\n");
        printf("%s\n", argv[1]);
        int i = 0;
        bool is_num;
        int num;
        while (argv[1][i] != '\0') 
        {
            num = isdigit(argv[1][i]);
            if (num != 0) 
            {
                is_num = true;
            } else 
            {
                is_num = false;
            }
            i++;
        }
        if (is_num == true)
        {
            num = atoi(argv[1]);
            printf("Num is %i\n", num);
        } else 
        {
           printf("Usage: ./caesar 23key\n");
        }
    }
    if (argc==1 || argc > 2)
    {
        printf("Usage: ./caesar key\n");
    }
}
