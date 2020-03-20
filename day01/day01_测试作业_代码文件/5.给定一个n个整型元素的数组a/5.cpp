#include<iostream>	  	  //直接用排序做的
#include<vector>		  //对数组排序  
#include<algorithm>	      //中间的那个必然是出现频率最高的
using namespace std;		
int main() {
	int input_a;
	vector<int> a;			//动态数组暂存
	while (cin >> input_a) {//连续读入 数组的值
		if (input_a != -1) {
			a.push_back(input_a);
		}
		else {
			break;
		}
	}
	int temp;
	int i = (int)a.size / 2;
	for (int i = 0; i < a.size(); i++) {       //冒泡排序
		for (int j = 0; j < a.size() - 1; j++) { 
			if (a[j] > a[j + 1]) {	//前值大于后值 则后的值给前
				swap(a[j], a[j + 1]);
			}
		}
	}
	cout << a[i] << endl;
	return 0;
}

