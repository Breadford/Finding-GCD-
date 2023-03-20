#include "euclidgcd.h"
#pragma CHECK_MISRA("none")
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#pragma CHECK_MISRA("all")

int_fast32_t division(int_fast32_t num1, int_fast32_t num2)
{
    int_fast32_t quotient = 0;
    if (num1 == 0)
    {
        quotient = 0;

    }

    if (num2 == 0)
    {

        assert(num2 != 0);
    }

    /*MISRA converting int*/
    /*bool negResult = false;*/
    int_fast32_t negResult = 0;

    if (num1 < 0)
    {
        num1 = (-num1);
            if (num2 < 0)
            {
                num2 = (-num2);
            }
            else
            {
                negResult = 1;
            }
    }
    else
    {
        if (num2 < 0)
        {
            num2 = (-num2);
            negResult = 1;
        }

    }


    while (num1 >= num2)
    {
        num1 = num1 - num2;
        quotient++;
    }

    if (negResult)
    {
        quotient = (-quotient);
    }
    return quotient;

}


int_fast32_t findRem(int_fast32_t num, int_fast32_t divisor)
{
    return(num - (division(num, divisor)*divisor));
}

int_fast32_t gcd(int_fast32_t a, int_fast32_t b)
{
    int_fast32_t temp = 0;
    while (b != 0)
    {
        temp = findRem(a, b);
        a = b;
        b = temp;
    }
    return a;
}

int_fast32_t findGCD(const int_fast32_t arr[],const int_fast32_t n)
{
    int_fast32_t result = arr[0];
    int_fast32_t i = 0;
    for (i = 1; i < n; i++)
    {
        result = gcd(arr[i], result);

    }
    return result;
}
