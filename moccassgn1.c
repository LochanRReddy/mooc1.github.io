#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long num;
    do
    {
        num = get_long("Number : ");
    }
    while (num < 10);

    long dinum = num;

    int digits = 0;
    while(dinum > 0)
    {
        dinum = dinum/10;
        digits++;
    }

    if (digits == 16 || digits == 15 || digits == 13)
    {
        int dig[digits];
        long num1 = num;
        int sum2 = 0;
        int sum = 0;
        for (int i = 0; i < digits; i++)
        {
            dig[digits - 1- i] = num1 % 10;
            num1 = num1 / 10;
        }
        for (int i = 0; i <= digits; i = i + 2)
        {
            dig[i] = dig[i] * 2;
        }
        for (int i = 0; i <= digits; i = i + 2)
        {
            if (dig[i] > 9)
            {
                while(dig[i] > 0)
                {
                    int ld = dig[i] % 10;
                    sum2 = sum2 + ld;
                    dig[i] = dig[i] / 10;
                }
            }
            else
            {
                sum2 = sum2 + dig[i];
            }
        }
        for (int i = 1; i <= digits; i = i + 2)
        {
            sum = sum + dig[i];
        }
        sum = sum + sum2;

        if (sum % 10 == 0)
        {
            long std = num;
            while (std > 99)
            {
                std = std / 10;
            }
            if (std == 34 || std == 37)
            {
                printf("AMEX\n");
            }
            else if (std >= 51 && std <=55)
            {
                printf("MASTERCARD\n");
            }
            else if (std >= 40 && std < 50)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
