#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void) 
{
    //input text to define a grade
    string text = get_string("Text: \n");
    
    //Count amount of letters
    int count_letter = 0;
    int count_words = 1;
    bool is_letter;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            count_letter++;
        } 
        if (text[i] == 32 && ((text[i+1] >= 65 && text[i+1] <= 90) || (text[i+1] >= 97 && text[i+1] <= 122))) 
        {
            count_words++;
        }
    }
    printf("Number of letters is: %i\nNumber of words is: %i\n", count_letter, count_words);
    
    
}