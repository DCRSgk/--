#include<iostream>	  	  //ֱ������������
#include<vector>		  //����������  
#include<algorithm>	      //�м���Ǹ���Ȼ�ǳ���Ƶ����ߵ�
using namespace std;		
int main() {
	int input_a;
	vector<int> a;			//��̬�����ݴ�
	while (cin >> input_a) {//�������� �����ֵ
		if (input_a != -1) {
			a.push_back(input_a);
		}
		else {
			break;
		}
	}
	int temp;
	int i = (int)a.size / 2;
	for (int i = 0; i < a.size(); i++) {       //ð������
		for (int j = 0; j < a.size() - 1; j++) { 
			if (a[j] > a[j + 1]) {	//ǰֵ���ں�ֵ ����ֵ��ǰ
				swap(a[j], a[j + 1]);
			}
		}
	}
	cout << a[i] << endl;
	return 0;
}

