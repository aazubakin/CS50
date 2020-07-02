#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height = 0;
    while ((height < 1) || (height > 8)) 
    {
        height = get_int("Enter height of pyramid from 1 to 8\n");
    }
    for (int i = height; i > 0; i--) 
    {
        for (int j = 1; j < i; j++) 
        {
            printf(" ");
        }
        for (int x = 0; x <= height - i; x++) 
        {
            printf("#");
        }
        printf("\n");
    }
}