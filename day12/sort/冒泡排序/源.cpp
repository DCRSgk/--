#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
constexpr auto N = 10;
void bubbleSort(int* Arr);
void arrPrint(int* arr);
using namespace std;
int main()
{
    int Arr[N];
    srand(time_t(NULL)); //���������
    time_t start, end;
    for (int i = 0; i <= N; i++)
    {
        Arr[i] = rand() % 100;
    }
    cout << "ԭ����Ϊ" << endl;
    arrPrint(Arr);
    cout << "------------------------------" << endl;
    //bubbleSort(Arr);
	//cout << "�����Ϊ" << endl;
    cout << "------------------------------" << endl;
    //arrPrint(Arr);
}

//void bubbleSort(int* Arr)
//{
//    for (int i = 0; i <= N; i++)
//    {
//        for (int j = 0; j < N - i; j++)
//        {
//            if (Arr[i] > Arr[i + 1])
//            {
//                swap(Arr[i], Arr[i + 1]);
//            }
//        }
//    }
//}
void arrPrint(int* arr)
{
    for (int i = 0; i < N; i++)
    {
        printf("%3d", arr[i]);
    }
    printf("\n");
}