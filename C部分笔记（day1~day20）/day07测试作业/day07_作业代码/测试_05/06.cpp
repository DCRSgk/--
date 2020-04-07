#include<iostream>  
#include<cstdio>
using namespace std;
constexpr auto N = 1024;
int main()
{
    int i;
    char a[N];
    gets_s(a);
    for (i = 0; a[i] != '\0';) {
        if (a[i] == ' ') {          //如果是空格输出一个空格
            cout<<" ";
            while (a[i] == ' ') i++; //向后继续循环到不是空格为止
        }
        else {                      //如果字符不是空格直接输出
            cout<<a[i];
            i++;
        }
    }
    cout << endl;
    return 0;
}