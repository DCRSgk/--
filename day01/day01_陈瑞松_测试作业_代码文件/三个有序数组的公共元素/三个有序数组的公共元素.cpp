#include<iostream>			 //三指针 
#include<vector>			 //都相等则输出
using namespace std;		 //若不全相等 则找出最大值 
int Max(int a, int b, int c);//剩下两个指针向右移
int main() {
	int input_a, input_b,input_c;
	vector<int> a;
	vector<int> b;
	vector<int> c;
	while (cin >> input_a) {
		a.push_back(input_a);
	}
	while (cin >> input_b) {
		b.push_back(input_b);
	}
	while (cin >> input_c) {
		c.push_back(input_c);
	}
	int i = 0, j = 0, k = 0;
	while (i < a.size() && j < b.size() && k < c.size) { //谁大谁不动 谁小谁往前走
		if (a[i] == b[j] && a[i] == c[k]) { //相等则直接输出
			cout << a[i] << ' ';
			i++;
			j++;
			k++;
			continue;
		}
		else if (i == a.size() && j == b.size() && k == c.size) { //如果某个数组取到端点
			break;												  //则直接跳出循环
		}
		else {							//剩下的所有情况 都先取最大值 然后两个较小的指针移动
			Max(a[i], b[j], c[k]);
			if (a[i] == Max(a[i], b[j], c[k])) {//a数组为最大时
				j++;							//数组b和c的指针移动
				k++;
			}
			else if (b[j] == Max(a[i], b[j], c[k])) {//b数组为最大时
				i++;								 //数组a和c的指针移动
				k++;
			}
			else if (c[k] == Max(a[i], b[j], c[k])) {//c数组为最大时
				i++;								 //数组a和b的指针移动
				j++;
			}
		}
	}
	return 0;
}
int Max(int a, int b, int c) {
	if (a > b && a > c) {
		return a;
	}
	else if (b > a && b > c) {
		return b;
	}
	else {
		return c;
	}
}