#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main() 
{
	char b[5][10] = { "lele","lili","lilei","hanmeimei","hhh" };
    char(*p)[10]= b;             //����һ��ָ��ָ������b��ÿһ��
    char temp[10];
    for(int i=0;i<=4;i++)
    {
        if (strcmp(p[i], p[i + 1]) ) //����p[ ]��һ�����飬�޷�ֱ�Ӹ�ֵ��������Ҫ�õ�strcpy
        {
            strcpy(temp, p[i]);
            strcpy(p[i], p[i + 1]);
            strcpy(p[i + 1], temp);
        }
        cout << p[i] << endl;
    }
}