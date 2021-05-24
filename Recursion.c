#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void logBase2(int n, int result)
{
    //printf("%d\n", n);
    if (n <= 2)
    {
        printf("%d\n", result);
        return;
    }
    else
    {
        logBase2(n / 2, result + 1);
    }
}

int power(int num, int exp)
{
    if (exp != 0)
    {
        return (num * (power(num, exp - 1)));
    }
    else
    {
        return 1;
    }
}

int fibonacci(int index)
{
    if (index == 0)
    {
        return 0;
    }
    if (index == 1)
    {
        return 1;
    }
    else
    {
        return fibonacci(index - 1) + fibonacci(index - 2);
    }
}

int factorial(int num)
{
    if (num >= 1)
    {
        return num * factorial(num - 1);
    }
    else
    {
        return 1;
    }
}

int main(int argc, char const *argv[])
{
    logBase2(2048, 1);
    int total = power(8, 3);
    printf("\n%d\n", total);
    int fibo = fibonacci(15);
    printf("\n%d\n", fibo);
    int fact = factorial(5);
    printf("\n%d\n", fact);
    return 0;
}
