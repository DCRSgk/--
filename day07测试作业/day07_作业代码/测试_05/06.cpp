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
        if (a[i] == ' ') {          //����ǿո����һ���ո�
            cout<<" ";
            while (a[i] == ' ') i++; //������ѭ�������ǿո�Ϊֹ
        }
        else {                      //����ַ����ǿո�ֱ�����
            cout<<a[i];
            i++;
        }
    }
    cout << endl;
    return 0;
}