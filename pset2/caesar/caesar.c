#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc == 2) //check number command-line arguments should be 2
    {
        
        int i = 0;
        bool is_num;
        int num;
        while (argv[1][i] != '\0') 
        {
            num = isdigit(argv[1][i]);
            if (num != 0) // isdigit check if number return number, if not return 0
            {
                is_num = true;
            } 
            else 
            {
                is_num = false;
            }
            i++;
        }
        if (is_num == true) //all checks are done these is main code
        {
            num = atoi(argv[1]);
            //if all conditions is ok do cipher of incript the message plaintext
            char c;
            int index_c;
            int index_h;
            string p_text = get_string("plaintext: ");
            printf("ciphertext: ");
            for (i = 0; p_text[i] != '\0'; i++)
            {
                if (p_text[i] >= 65 && p_text[i] <= 90) //checkeing if uppercase
                {
                    index_c = p_text[i] - 65;
                    index_c = (index_c + num) % 26;
                    index_c = index_c + 65;
                    //printf("%i", index_c);
                    c = (char)index_c;
                    printf("%c", c);
                } 
                if (p_text[i] >= 97 && p_text[i] <= 122) //checking if lowcase
                {
                    index_c = p_text[i] - 97;
                    index_c = (index_c + num) % 26;
                    index_c = index_c + 97;
                    //printf("%i", index_c);
                    c = (char)index_c;
                    printf("%c", c);
                }
                if (isalpha(p_text[i]) == false) //if not alphabetic live charachter as is
                {
                    printf("%c", p_text[i]);
                }
            }
            printf("\n");
        } 
        else //if not a number or there are not digit
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    if (argc == 1 || argc > 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}
