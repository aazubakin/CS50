#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void) 
{
    //input text to define a grade
    string text = get_string("Text: \n");
    
    //Count amount of letters
    int count_letter = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            count_letter++;
        }
    }
    printf("Number of letters is: %i\n", count_letter);
    
    
}