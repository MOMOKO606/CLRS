#include<iostream>
#include<fstream>
#include<math.h>
#include<vector>


using namespace std;


int Length(ifstream &input)
{
	input.clear();
	input.seekg(0, ios::beg);

	if (!input.is_open())
		cout << "Error in opening file!";

	int n = 0;
	int x;
	while (!input.eof()) {
		n++;
		input >> x;
	}
	return n - 1;
}


template<class T>
int Width(T *X, int dmax)
{
	int n = 0;
	int i = 0;
	while (X[i] == 0) {
		i++;
		n++;
	}
	return dmax - n;
}

template<class T>
void Read2A(ifstream &input, T *A, int n)
{
	input.clear();
	input.seekg(0, ios::beg);

	if (!input.is_open())
		cout << "Error in opening file!";

	for (int i = 0; i != n; i++)
		input >> A[i];
}


template<class T>
int GetDigitsNum(T x)
{
	int r = 10;
	int d = 0;
	while (x != 0) {
		x -= x%r;
		r *= 10;
		d++;
	}
	return d;
}


template<class T>
int MaxDigitsNum(T *A, int n)
{
	int dmax = -INFINITY;
	int d;
	for (int i = 0; i != n; i++) {
		d = GetDigitsNum(A[i]);
		if (d > dmax)
			dmax = d;
	}
	return dmax;
}


template<class T>
void CountingSort_digit(T *A, int n)
{
	int d;
	int dmax = MaxDigitsNum(A, n);
	int *B = new int[dmax + 1];

	for (int i = 0; i <= dmax; i++)
		B[i] = 0;
	for (int i = 0; i != n; i++) {
		d = GetDigitsNum(A[i]);
		B[d] += 1;
	}
	for (int i = 1; i <= dmax; i++)
		B[i] += B[i - 1];

	T *C = new T[n];
	for (int i = n - 1; i >= 0; i--) {
		d = GetDigitsNum(A[i]);
		C[B[d] - 1] = A[i];
		B[d] -= 1;
	}
	for (int i = 0; i != n; i++)
		A[i] = C[i];
}


template<class T>
vector<int> GetIndexTable(T *A, int n)
{
	int digit_end;
	int digit_begin = GetDigitsNum(A[0]);
	vector<int> Index;

	for (int i = 1; i != n; i++) {
		digit_end = GetDigitsNum(A[i]);
		if (digit_end != digit_begin) {
			Index.push_back(i - 1);
			digit_begin = digit_end;
		}
	}
	return Index;
}


template<class T>
void Change2Radix(T *A, T **Aux, int n, int m)
{
	int r;

	for (int i = 0; i != n; i++) {
		r = 10;
		for (int j = m - 1; j >= 0; j--) {
			int res = A[i] % r;

			Aux[i][j] = res * 10 / r;

			A[i] -= res;
			r *= 10;
		}
	}
}


template<class T>
void CopyRow(T **A, T **C, int i, int j, int m)
{
	for (int k = 0; k != m; k++)
		C[j][k] = A[i][k];
}


template<class T>
void CountingSort_2D(T **A, int st, int fsh, int dmax, int col)
{
	int n = fsh - st + 1;

	int *B = new int[10];
	for (int i = 0; i != 10; i++)
		B[i] = 0;
	for (int i = st; i <= fsh; i++)
		B[A[i][col]] += 1;
	for (int i = 1; i != 10; i++)
		B[i] += B[i - 1];

	T **C = new T*[n];
	for (int i = 0; i != n; i++)
		C[i] = new T[dmax];

	for (int i = fsh; i >= st; i--) {
		int j = B[A[i][col]] - 1;
		//A[i][]复制到C[j][]
		CopyRow(A, C, i, j, dmax);
		B[A[i][col]] -= 1;
	}

	for (int i = st; i <= fsh; i++) {
		for (int j = 0; j != dmax; j++)
			A[i][j] = C[i - st][j];
	}
}


template<class T>
void RadixSort(T **A, int st, int fsh, int dmax)
{
	int m = Width(A[st], dmax);
	int n = fsh - st + 1;

	for (int i = dmax - 1; i >= dmax - m; i--)
		CountingSort_2D(A, st, fsh, dmax, i);
}


int main()
{
	ifstream input("D:\\Temporary work data\\RadixSort2.txt");
	int n = Length(input);
	int *A = new int[n];
	Read2A(input, A, n);
	int m = MaxDigitsNum(A, n);

	//统计并按数字位数对A进行“粗排列”
	CountingSort_digit(A, n);

	//得到“粗排列”的Index
	vector<int> Index = GetIndexTable(A, n);

	//将“粗排列”后的A“散列”成二维数组；
	int **A_2D = new int *[n];
	for (int i = 0; i != n; i++)
		A_2D[i] = new int[n];
	Change2Radix(A, A_2D, n, m);

	//对“粗排列”后的每一段分别使用Radix Sort
	int fsh;
	int st = 0;
	int k = 0;
	int Index_length = Index.size();
	while (st < n) {
		k < Index_length ? fsh = Index[k++] : fsh = n - 1;
		RadixSort(A_2D, st, fsh, m);
		st = fsh + 1;
	}

	//显示计算结果
	for (int i = 0; i != n; i++) {
		for (int j = 0; j != m; j++)
			cout << A_2D[i][j];
		cout << endl;
	}

	delete[]A,A_2D;
	return 0;
}
