#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main() 
{
	char b[5][10] = { "lele","lili","lilei","hanmeimei","hhh" };
    char(*p)[10]= b;             //定义一个指针指向数组b的每一行
    for(int i=0;i<=4;i++)
    {
        if (strcmp(p[i], p[i + 1]) )
        {

         

        }
        cout << p[i] << endl;

    }
}