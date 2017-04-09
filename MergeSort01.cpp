#include<iostream>
#include<fstream>
#include<string>
#include<limits>
#include<math.h>

using namespace std;

int Length(ifstream &input)
{
	if (!input.is_open())
		cout << "Error in opening!";

	double x;
	int n = 0;

	while (!input.eof()) {
		input >> x;
		n++;
	}
	return n - 1;
}

template<class T>
void Read2A(ifstream &input, T *A,int n)
{
	input.clear();
	input.seekg(0, ios::beg);

	for (int i = 0; i != n; i++)
		input >> A[i];
}

template<class T>
void Merge(T *A, int p, int q, int r)
{
	//将A的左右两部分分别赋值给L，R数组
	int n1 = q - p + 1;
	int n2 = r - q;
	T *L = new T[n1 + 1];
	T *R = new T[n2 + 1];
	for (int i = p; i <= q; i++)
		L[i-p]=A[i];
	for (int i = q + 1; i <= r; i++)
		R[i-q-1]=A[i];
	L[n1] = (numeric_limits<double>::max)();
	R[n2] = (numeric_limits<double>::max)();
	//Merge
	int i = 0;
	int j = 0;
	for (int k = p; k <= r; k++) {
		if (L[i] <= R[j])
			A[k] = L[i++];
		else
			A[k] = R[j++];
	}
}

template<class T>
void MergeSort(T *A,int p,int r)
{
	if (p < r) {
		int q =floor( (p + r-1) / 2);
		MergeSort(A, p, q);
		MergeSort(A, q+1, r);
		Merge(A, p, q, r);
	}
}

int main()
{
	ifstream input("D:\\Temporary work data\\test.txt");
	//得到文件长度
	int n = Length(input);

	//将文件读入到A
	double *A = new double[n];
	Read2A(input, A, n);

	//Merge Sort
	MergeSort(A, 0, n - 1);

	//输出结果
	for (int i = 0; i != n; i++)
		cout << A[i] << endl;
	delete[]A;
	return 0;
}
