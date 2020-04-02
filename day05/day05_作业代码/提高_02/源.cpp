#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int arr[100][100] ;
    int val = 0;
    int n = 3;
    int i, j;
    for (int m = 0, k = m - 1; m <= k; ++m, --k)
    {
        for (i = m, j = m; j <= k; ++j)
        {
            arr[i][j] = val++;
        }
        for (i = m + 1, j = k; i <= k; ++i)
        {
            arr[i][j] = val++;
        }
        for (i = k, j = k - 1; j >= m; --j)
        {
            arr[i][j] = val++;
        }
        for (i = k - 1, j = m; i >= m + 1; --i)
        {
            arr[i][j] = val++;
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%4d", arr[i][j]);
        }
        cout << endl;
    }
}