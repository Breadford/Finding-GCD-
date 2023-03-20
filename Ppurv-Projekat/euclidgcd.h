#ifndef EUCLIDGCD_H_
#define EUCLIDGCD_H_
#pragma CHECK_MISRA("none")
#include <stdint.h>
#pragma CHECK_MISRA("all")

int_fast32_t division(int_fast32_t num1, int_fast32_t num2);
int_fast32_t findRem(int_fast32_t num, int_fast32_t divisor);
int_fast32_t gcd(int_fast32_t a, int_fast32_t b);
int_fast32_t findGCD(const int_fast32_t arr[],const int_fast32_t n);

#endif



