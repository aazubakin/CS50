#include <stdio.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    //check number command-line arguments
    if (argc == 2)
    {
        printf("Success\n");
        printf("%s\n", argv[1]);
    }
    if (argc==1 || argc > 2)
    {
        printf("Usage: ./caesar key\n");
    }
}
