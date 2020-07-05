#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void) 
{
    //input text to define a grade
    string text = get_string("Text: ");
    
    //Count amount of letters
    int count_letters = 0;
    int count_words = 0;
    int count_sentences = 0;
    //Checking if print empty string
    if ((text[0] >= 65 && text[0] <= 90) || (text[0] >= 97 && text[0] <= 122))
    {
        count_words = 1;
        count_sentences = 1;
    }
    //counting letters words and senteces
    for (int i = 0; text[i] != '\0'; i++)
    {
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            count_letters++;
        } 
        if (text[i] == 32 && ((text[i + 1] >= 65 && text[i + 1] <= 90) || (text[i + 1] >= 97 && text[i + 1] <= 122))) 
        {
            count_words++;
        }
        if ((text[i] == 33 || text[i] == 46 || text[i] == 63) && text[i + 1] != '\0')
        {
            count_sentences++;
        }
    }
    //Coleman-Liau Index formula index = 0.0588 * L - 0.296 * S - 15.8 
    //where L is average number of letters per 100 words
    //S is average number of sentences
    float L;
    float S;
    L = (float) count_letters / (float) count_words * 100;
    S = (float) count_sentences / (float) count_words * 100;
    
    int index;
    index = round(0.0588 * L - 0.296 * S - 15.8);
    //Grade should print number between 1 and 16 
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    if (index >= 1 && index <= 16)
    {
        printf("Grade %i\n", index);
    }

}