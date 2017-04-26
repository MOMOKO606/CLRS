//CLRS P18: Insertion sort
//using cin, functions

#include <iostream>

using namespace std;

void InsertionSort(double *A,int n)
{
	for (int i = 1; i != n; i++) {
		double key = A[i];
		int j = i - 1;
		while (A[j]>key && j >= 0) {
			A[j + 1] = A[j];
			--j;
		}
		A[j + 1] = key;
	}
}

int main()
{
	//输入数组长度
	int n;
	cin >> n;

	//输入A数组
	double *A=new double[n];
	for (int i = 0; i != n; i++)
		cin >> A[i];

	//Insertion Sort
	InsertionSort(A, n);

	//输出结果
	cout << endl;
	for (int i = 0; i != n; i++)
		cout << A[i] << endl;

	delete[]A;

	return 0;
}
