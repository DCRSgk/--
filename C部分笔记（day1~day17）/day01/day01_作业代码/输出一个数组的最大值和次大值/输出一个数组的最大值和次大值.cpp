#include<iostream>
#include<vector>
using namespace std;
int main() {
	vector<int> a;
	int input_a;
	while (cin >> input_a) {
		a.push_back(input_a);

	}
	int i = 0;
	int Max = 0;
	int Sub_Max = 0;
	while (i < a.size()){
		if (Max < a[i] && Sub_Max<a[i] ) { //�����С  ����Max��ֵ����Max��Sub_Max
			Max = a[i];
			Sub_Max = Max;
		}
		if (Max > a[i] && Sub_Max < a[i]) { //�����MaxС����Sub_Max�� �������Sub_Max
			Sub_Max = a[i];
		}
		else {								//������� �����ѭ�� i++
			continue;
		}	
		i++;
	}
	return 0;
}