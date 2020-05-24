#include"myLibrary.h"
int main()
{
    int m=3;
    int n=3;
    int path;
    path = Factorial(m + n) / (Factorial(m) * Factorial(m + n - m));
    printf("走到（%d，%d），有%d种方法\n", m, n, path);
}