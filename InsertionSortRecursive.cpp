#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int Length(ifstream& input)
{
	if (!input.is_open())
		cout << "Error opening file!" << endl;

	double x;
	int n = 0;

	while (!input.eof()) {
		input >> x;
		n++;
	}
	return n - 1;
}

template<class T>
void Read2A(ifstream &input,T A[], int n)
{
	input.clear();
	input.seekg(0, ios::beg);

	for (int i = 0; i != n; i++)
		input >> A[i];
}

template<class T>
void Insert(T A[], int n)
{
	T key = A[n];
	int j = n - 1;
	while (A[j] > key && j >= 0) {
		A[j + 1] = A[j];
		j--;
	}
	A[j + 1] = key;
}

template<class T>
void InsertionSort_Recursive(T A[],int n)
{
	if (n == 1)
		return;
	InsertionSort_Recursive(A, n-1);
	Insert(A, n);
}

int main()
{
	ifstream input("D:\\test.txt");
	//读文件长度
	int n = Length(input);

	//将文件读入数组A中
	double *A = new double(n);
	Read2A(input, A, n);

	//InsertionSort Recursive版本
	InsertionSort_Recursive(A, n);

	//输出计算结果
	for (int i = 0; i != n; i++)
		cout << A[i] << endl;

	return 0;
	delete[]A;
}
