#include<iostream>			 //��ָ�� 
#include<vector>			 //����������
using namespace std;		 //����ȫ��� ���ҳ����ֵ 
int Max(int a, int b, int c);//ʣ������ָ��������
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
	while (i < a.size() && j < b.size() && k < c.size) { //˭��˭���� ˭С˭��ǰ��
		if (a[i] == b[j] && a[i] == c[k]) { //�����ֱ�����
			cout << a[i] << ' ';
			i++;
			j++;
			k++;
			continue;
		}
		else if (i == a.size() && j == b.size() && k == c.size) { //���ĳ������ȡ���˵�
			break;												  //��ֱ������ѭ��
		}
		else {							//ʣ�µ�������� ����ȡ���ֵ Ȼ��������С��ָ���ƶ�
			Max(a[i], b[j], c[k]);
			if (a[i] == Max(a[i], b[j], c[k])) {//a����Ϊ���ʱ
				j++;							//����b��c��ָ���ƶ�
				k++;
			}
			else if (b[j] == Max(a[i], b[j], c[k])) {//b����Ϊ���ʱ
				i++;								 //����a��c��ָ���ƶ�
				k++;
			}
			else if (c[k] == Max(a[i], b[j], c[k])) {//c����Ϊ���ʱ
				i++;								 //����a��b��ָ���ƶ�
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