#include<iostream>			//�ڶ��ֲ��Һ�˫ָ�뷨֮�䷴������ ������ȥ����˫ָ���
#include<vector>//�������������ʼλ����������ָ��
using namespace std;		//�Ƚ϶��ߴ�С ˭��˭������˭С˭��ǰ��
int main(){
	int input_a, input_b ;
	vector<int> a;			//��̬�����ݴ�
	vector<int> b;
	while (cin >> input_a){//��������
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
	int i = 0, j = 0;//��������ָ��
	while (i < a.size() && (j < b.size())){ //˭��˭���� ˭С˭��ǰ��
		if (a[i] == b[j]) {             //�����ֱ�����
		cout << a[i] << ' ';
		i++;
		j++;
		continue;
		}		
		else if (a[i] < b[j]) {      //b����a��ָ��++
			i++;
		}		

		else {						//a����b��ָ��++
			j++;
		}
	}
}