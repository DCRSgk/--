#include<iostream>
#include<cstdio>
#include<string>
#include<cstdlib>
#include <time.h>
constexpr auto MAXKEY = 20;
using namespace std;
int gethash(char* key);

int main()
{
	char Arr[20][10] = {
		"chunyang","qixiu","wanhua","shaolin","cangjian","badao","mingjiao","tiance","wudu","tangmen","gaibang","cangyun"
		,"changge","penglai","lingxue","chenwei","tanmoti","zhen","renheyi","jiafei" };
	int hashMap[20] = { 0 };
	for (int i = 0; i < MAXKEY; i++) {
		hashMap[i]=gethash((char*)Arr[i]);
	}
	char j[MAXKEY];
	cin >> j;
	int m = gethash(j);
	for (int i = 0; i < MAXKEY; i++)
	{
		if (m == hashMap[i])
		{
			cout << i << endl;
		}
	}
}
int gethash(char* key) {
	int h = 0, g;
	while (*key) {
		h = (h << 4) + *key++;
		g = h & 0xf0000000;
		if (g)
			h ^= g >> 24;
		h &= ~g;
	}
	return h % MAXKEY;
}