#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main() 
{
	char b[5][10] = { "lele","lili","lilei","hanmeimei","hhh" };
    char(*p)[10]= b;             //定义一个指针指向数组b的每一行
    char temp[10];
    for(int i=0;i<=4;i++)
    {
        if (strcmp(p[i], p[i + 1]) ) //由于p[ ]是一个数组，无法直接赋值。所以需要用到strcpy
        {
            strcpy(temp, p[i]);
            strcpy(p[i], p[i + 1]);
            strcpy(p[i + 1], temp);
        }
        cout << p[i] << endl;
    }
}