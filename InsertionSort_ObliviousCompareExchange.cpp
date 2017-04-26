//CLRS P208,Problems 8-7: Insertion sort
//Using oblivious compare-exchange algorithm

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int Length(ifstream &input)
{
	if (!input.is_open())
		cout << "Error!" << endl;

	double x;
	int n=0;
	while (!input.eof()) {
		input >> x;
		n++;
	}
	return n - 1;
}

template<class T>
void Read2A(ifstream &input,T A[],int n)
{
	input.clear();
	input.seekg(0, ios::beg);

	for (int i = 0; i != n; i++)
		input >> A[i];
}

template<class T>
void Exchange(T &x,T &y)
{
	T temp;
	temp = x;
	x = y;
	y = temp;
}

template<class T>
void OCExchange(T A[], int i, int j)
{
	if (A[i] > A[j])
		Exchange(A[i], A[j]);
}

template<class T>
void InsertionSort(T A[],int n)
{
	for (int i = 1; i != n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			OCExchange(A, j, j + 1);
		}
	}
}

int main()
{
	//读入文件长度
	ifstream input("D:\\Temporary work data\\test.txt");
	int n = Length(input);

	//读入文件到A数组
	double* A = new double(n);
	Read2A(input, A, n);

	//插入排序
	InsertionSort(A,n);

	//输出结果
	for (int i = 0; i != n; i++)
		cout << A[i] << endl;
	delete[]A;

	return 0;
}
