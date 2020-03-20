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
		if (Max < a[i] && Sub_Max<a[i] ) { //如果都小  重置Max的值并把Max给Sub_Max
			Max = a[i];
			Sub_Max = Max;
		}
		if (Max > a[i] && Sub_Max < a[i]) { //如果比Max小但比Sub_Max大 则仅重置Sub_Max
			Sub_Max = a[i];
		}
		else {								//如果都大 则继续循环 i++
			continue;
		}	
		i++;
	}
	return 0;
}