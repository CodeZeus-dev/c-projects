//
// Created by Constantine Akritides on 23/07/2020.
//
#include <stdio.h>
#include <math.h>
#include <cs50.h>

/*The scope of this c code is to examine the validity of a credit card number
and to determine the type of credit card.*/

int main(void)
{
    /* Define card number and ask for the user to type it in */
    long card_number = get_long("Number: ");
    int nDigits = floor(log10(card_number)) + 1;

    if ((nDigits != 13) && (nDigits != 15) && (nDigits != 16))
    {
        printf("INVALID\n");
    }
    else
    {
        int otherSum = 0, remainderSum = 0;
        long otherNumber = (card_number - (card_number % 10)) / 10;
        long remainderNum = card_number;

        for (int i = 0; i < nDigits; i++)
        {
            if ((floor(log10(2 * (otherNumber % 10))) + 1) == 2)
            {
                otherSum += (2 * (otherNumber % 10)) % 10 + (2 * (otherNumber % 10)) / 10;
            }
            else
            {
                otherSum += 2 * (otherNumber % 10);
            }

            remainderSum += remainderNum % 10;

            if ((floor(log10(otherNumber)) + 1 == 1) && (nDigits % 2 == 0))
            {
                break;
            }
            else if ((floor(log10(remainderNum)) + 1 == 1) && (nDigits % 2 != 0))
            {
                break;
            }

            otherNumber = (((otherNumber - (otherNumber % 10)) / 10) -
                           (((otherNumber - (otherNumber % 10)) / 10)) % 10) / 10;
            remainderNum = (((remainderNum - (remainderNum % 10)) / 10) -
                            (((remainderNum - (remainderNum % 10)) / 10)) % 10) / 10;
        }

        int totSum = otherSum + remainderSum;

        bool valid;
        int firstDigit = (int)(card_number / pow(10, floor(log10(card_number))));
        int secondDigit = (int)(card_number / pow(10, floor(log10(card_number)) - 1)) % 10;

        if (totSum % 10 == 0)
        {
            valid = true;
            if (((firstDigit == 5) && (secondDigit == 1 || secondDigit == 2 ||
                                       secondDigit == 3 || secondDigit == 4 ||
                                       secondDigit == 5)) && (nDigits == 16))
            {
                printf("MASTERCARD\n");
            }
            else if (((firstDigit == 3) && (secondDigit == 4 || secondDigit == 7)) &&
                     (nDigits == 15))
            {
                printf("AMEX\n");
            }
            else if ((firstDigit == 4) && ((nDigits == 13) || (nDigits == 16)))
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
            valid = false;
            printf("INVALID\n");
        }
    }
}

