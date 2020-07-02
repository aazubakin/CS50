#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void) 
{
    //input number of change
    float change = 0;
    while (change <= 0) 
    {
        change = get_float("How much change is owed? (dollars point cents or just dollars)\n");
    }
    
    int cents = round(change * 100);
    //calculate cents
    //cents = cents % 100;
    int coins = 0;
    //calculate count of quoters
    coins = round(cents / 25);
    cents = cents % 25;
    //count of dimes
    coins = coins + round(cents / 10);
    cents = cents % 10;
    //count of nickels
    coins = coins + round(cents / 5);
    cents = cents % 5;
    //count of pennies
    coins = coins + round(cents / 1);
    
    printf("%d\n", coins);
    
    
}