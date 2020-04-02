#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<string>
#include <time.h>
constexpr auto N = 20;
using namespace std;
void shellSort(int* arr);
int partition(int* arr, int left, int right);
void quickSort(int* arr, int left, int right);
void quickSort2(int* arr, int left, int right);
void selectSort(int* Arr);