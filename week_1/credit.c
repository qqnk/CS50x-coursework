#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long ccNumber;
    int sum = 0;

    // get cc number
    do
    {
        ccNumber = get_long("what is credit card number\n");
    }
    while (ccNumber < 0);

    // copy cc number to working version
    long workingCC = ccNumber;

    // multiply every other number + determine sum2 (case 2)
    long workingCC2 = (workingCC / 10);
    int sum2 = 0;
    while (workingCC2 > 0)
    {
        int lastDigit = workingCC2 % 10;
        lastDigit = (lastDigit * 2);
        sum2 = (sum2 + (lastDigit % 10) + (lastDigit / 10));
        workingCC2 = (workingCC2 / 100);
    }

    // add every other number + determine sum1 (case 1)
    long workingCC1 = workingCC;
    int sum1 = 0;
    while (workingCC1 > 0)
    {
        int lastDigit = workingCC1 % 10;
        sum1 = (sum1 + lastDigit);
        workingCC1 = (workingCC1 / 100);
    }

    // total sum
    sum = sum1 + sum2;

    // calculate length of ccNumber
    int i = 0;
    while (workingCC > 0)
    {
        workingCC = workingCC / 10;
        i++;
    }

    // determine ccNumber starting values
    long firstDivider = pow(10, (i - 1));
    long firstTwoDivider = pow(10, (i - 2));

    long firstDigit = ccNumber / firstDivider;
    long firstTwoDigits = ccNumber / firstTwoDivider;

    // checksum and print type
    if (firstDigit == 4 && (i == 13 || i == 16))
    {
        printf("VISA\n");
    }
    else if ((firstTwoDigits == 34 || firstTwoDigits == 37) && i == 15)
    {
        printf("AMEX\n");
    }
    else if ((firstTwoDigits > 50 && firstTwoDigits < 56) && i == 16)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
