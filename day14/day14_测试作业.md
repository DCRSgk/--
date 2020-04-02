测试作业

1 完成二叉查找

```c++
int binarySearch(int* arr, int key)
{
	int left = 0;
	int right = N-1;
	while (left<=right)
	{
		int mid;
		mid = (left + right) / 2;
		if (arr[mid] = key)
		{
			return mid;
		}
		else if (arr[mid]>key)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return 0;
}
```

### 2 往一个字符串数组当中插入20个不同的字符串，然后输入一个字符串，使用下列哈希算法判断该字符串是否出现在数组当中，如果出现，它的下标是多少？

int hash(char *key) {

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

```c++
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
```

3 实现二叉排序树的插入

4 实现二叉排序树的左旋和右旋

5 整理红黑树的各种情况，写出伪代码，如果时间充足的同学可以直接实现红黑树的插入

*6 实现二叉排序树的删除