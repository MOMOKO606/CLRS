//更新读取矩阵行列数函数
//定义二维动态矩阵

#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>

using namespace std;

int RowsofMatrix(ifstream &input)
{
	if (!input.is_open())
		cout << "Error in opening file!";

	input.clear();
	input.seekg(0, ios::beg);

	string temp;
	int m = 0;

	while (getline(input, temp, '\n')) {
		m++;
	}
	return m;
}

int ColumnsofMatrix(ifstream &input)
{
	if (!input.is_open())
		cout << "Error in opening file!";

	input.clear();
	input.seekg(0, ios::beg);

	double x;
	int n = 0;

	while (input >> x) {
		n++;
		if (input.peek() == '\n')
			break;
	}
	return n;
}

template<class T>
void Read2A(ifstream &input, T *A, int m, int n)
{
	input.clear();
	input.seekg(0, ios::beg);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			input >> A[i][j];
		}
	}
}

template<class T>
void Exchange(T **A, int i, int j, int col)
{
	T temp;
	for (int k = 0; k < col; k++) {
		temp = A[i][k];
		A[i][k] = A[j][k];
		A[j][k] = temp;
	}
}


template<class T>
void FuzzySort(T *A, int p, int r)
{
	if (p < r) {
		int t = r;
		int q = Randomized_PartitionFS(A, p, r, t);
		FuzzySort(A, p, t - 1);
		FuzzySort(A, q + 1, r);
	}
}

template<class T>
int Randomized_PartitionFS(T *A, int p, int r,int &t)
{
	int i = rand() % (r - p + 1) + p;
	Exchange(A, i, r, 2);
	return PartitionFS(A, p, r, t);
}

template<class T>
int PartitionFS(T **A, int p, int r,int &t)
{
	T pivot = A[r][1];
	int j = p - 1;
	for (int i = p; i <= r - 1; i++) {
		if (!(A[i][0] > pivot))
			Exchange(A, i, ++j, 2);
	}
	Exchange(A, r, ++j, 2);
	int q = j;

	pivot = A[q][0];
	j = p - 1;
	for (int i = p; i < q; i++) {
		if(A[i][1] < pivot)
			Exchange(A, i, ++j, 2);
	}
	t = ++j;
	return q;
}

int main()
{
	ifstream input("D:\\Temporary work data\\FuzzySort Test.txt");
	int row = RowsofMatrix(input);
	int col = ColumnsofMatrix(input);

	double **A = new double *[row];
	for (int i = 0; i < row; i++)
		A[i] = new double[col];

	Read2A(input, A, row, col);
	FuzzySort(A, 0, row - 1);

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			cout << A[i][j] << "\t";
		cout << endl;
	}


	for (int i = 0; i < row; ++i)
		delete[]A[i];

	delete[]A;

	return 0;
}
