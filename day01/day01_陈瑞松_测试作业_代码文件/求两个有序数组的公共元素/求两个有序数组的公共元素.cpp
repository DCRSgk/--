#include<iostream>			//在二分查找和双指针法之间反复横跳 想来想去还是双指针吧
#include<vector>//在两个数组的起始位置设置两个指针
using namespace std;		//比较二者大小 谁大谁不懂，谁小谁往前走
int main(){
	int input_a, input_b ;
	vector<int> a;			//动态数组暂存
	vector<int> b;
	while (cin >> input_a){//连续读入
		if (input_a != -1) {
			a.push_back(input_a);
		}
		else {
			break;
		}
	}
	while (cin >> input_b){
		if (input_b != -1) {
			b.push_back(input_b);
		}
		else {
			break;
		}
	}
	int i = 0, j = 0;//设立两个指针
	while (i < a.size() && (j < b.size())){ //谁大谁不动 谁小谁往前走
		if (a[i] == b[j]) {             //相等则直接输出
		cout << a[i] << ' ';
		i++;
		j++;
		continue;
		}		
		else if (a[i] < b[j]) {      //b大则a的指针++
			i++;
		}		

		else {						//a大则b的指针++
			j++;
		}
	}
}