#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int Length( ifstream &input )
{
	//检测文件是否打开
	if (!input.is_open())
		cout << "Error opening file!";

	double x;
	int n = 0;

	while (!input.eof()) {
		input >> x;
		n++;
	}
	return n - 1;
}

template<class T>
void Read2A(ifstream &input,T *A,int n)
{
	//指针指回文件头
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
void SelectionSort(T *A, int n)
{
	for (int i = 0; i <= n - 2; i++) {
		T min = A[i];
		int k = i;
		for (int j = i + 1; j <= n-1; j++) {
			if (A[j] < min) {
				min = A[j];
				k = j;
			}
		}
		Exchange(A[i], A[k]);
	}
}

int main()
{
	ifstream input("D:\\Temporary work data\\test.txt");
	int n = Length(input);

	double *A = new double[n];
	Read2A(input, A, n);

	SelectionSort(A,n);

	for (int i=0; i != n; i++)
		cout << A[i] << endl;

	delete[]A;

	return 0;
}
