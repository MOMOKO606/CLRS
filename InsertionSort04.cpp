//CLRS P18: Insertion sort
//using file, functions

#include <iostream>
#include <fstream>
#include<string>

using namespace std;

template<class T>
void InsertionSort(T A[], int n)
{
	for (int i = 1; i != n; i++) {
		T key = A[i];
		int j = i - 1;
		while (A[j]>key && j >= 0) {
			A[j + 1] = A[j];
			--j;
		}
		A[j + 1] = key;
	}
}

int Length(ifstream &input)
{
	//检测是否打开文件
	if (!input.is_open())
		cout << "Error opening file";
	//计算一维数组长度
	int n=0;
	double x;

	while (!input.eof()) {
		input >> x;
		n++;
	}
	return n-1;
}

void Read2A(ifstream &input, double *A,int n)
{
	//指针指回文件头
	input.clear();
	input.seekg(0, ios::beg);
	for(int i = 0; i != n; i++ )
		input >> A[i];
}

int main()
{
	ifstream input("D:\\Temporary work data\\test.txt");
	//读入文件中一维数组的长度n
	int n=Length(input);

	//创建数组A
	double *A = new double[n];
	Read2A(input, A, n);

	//Insertion Sort
	InsertionSort(A, n);

	//输出结果
	cout <<n<< endl;
	for (int i = 0; i != n; i++)
		cout << A[i] << endl;

	delete[]A;

	return 0;
}
