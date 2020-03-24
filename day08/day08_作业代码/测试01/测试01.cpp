#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
constexpr auto N = 1024;
void input() 
{


}
int bigadd(char num1[], char num2[]);
int main()
{
	bool num1_sign = true, num2sign = true, result = true;
	int num1_size, num2_size;
	char num1[N];
	int num1_in[N] ;
	char num2[N];
	int num2_in[N];
	int Sum[N] = { 0 };
	cin >> num1;
	cin >> num2;
	num1_size = strlen(num1);
	num2_size = strlen(num1);
	if (num1[0] == '-') num1_sign = false;
	if (num2[0] == '-') num2sign = false;
	if (num1_sign && num2sign) result = true; //判断正负 都正||都负均可按照加法运算
	else if (num1_sign == 0 && num2sign == 0) result = true;
	else result = false; //一正一负则要比较大小

}

