#include<iostream>  //������ǿ����̰���㷨 ��š�����
#include<vector>
#include<cmath>
using namespace std;
int main() {
	vector<int>a;
	int input_a;
	while (cin >> input_a) {
		a.push_back(input_a);
	}
	int x = a[0];
	int y = a[1];
	int Min = abs(x - y);
	for (int i = 0; i < a.size(); i++) {  //��������
		if (abs(a[i] - a[i + 1]) < Min) { //������ֱ�Min��С�� ������x y Min��ֵΪ��ǰֵ
			x = a[i];
			y = a[i - 1];
			Min = abs(a[i] - a[i + 1]);
		}
	}
	cout << "x = " << x << " "
		 << "y = " << y << " "
		 << "abs(x-y) = " 
		 << Min << endl;
	return 0;
}