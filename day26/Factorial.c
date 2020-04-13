#include "myLibrary.h"
int Factorial(int n)
{
    long long m = 1;
    for(int i=1;i<=n;i++)
    {
        m *= i;
    }
    return m;
}