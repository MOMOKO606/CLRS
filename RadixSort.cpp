#include<iostream>
#include<fstream>

using namespace std;

int Length(ifstream &input)
{
	input.clear();
	input.seekg(0, ios::beg);

	if (!input.is_open())
		cout << "Error in opening file!";

	int x;
	int n = 0;
	while (!input.eof()) {
		input >> x;
		n++;
	}
	return n - 1;
}

template<class T>
void Read2A(ifstream &input, T A, int n)
{
	input.clear();
	input.seekg(0, ios::beg);

	if (!input.is_open())
		cout << "Error opening file!";

	for (int i = 0; i != n; i++)
		input >> A[i];
}

template<class T>
int RadixNum(T x)
{
	int r = 10;
	int m = 0;
	while (x != 0) {
		x -= x % r;
		r *= 10;
		m++;
	}
	return m;
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
void CountingSort(T **A, int n, int m, int col)
{
	int *B = new int[10];
	for (int i = 0; i != 10; i++)
		B[i] = 0;
	for (int i = 0; i != n; i++)
		B[A[i][col]] += 1;
	for (int i = 1; i != 10; i++)
		B[i] += B[i - 1];

	T **C = new T*[n];
	for (int i = 0; i != n; i++)
		C[i] = new T[m];

	for (int i = n - 1; i >= 0; i--) {
		int j = B[A[i][col]] - 1;
		//A[i][]复制到C[j][]
		CopyRow(A, C, i, j, m);
		B[A[i][col]] -= 1;
	}

	for (int i = 0; i != n; i++) {
		for (int j = 0; j != m; j++)
			A[i][j] = C[i][j];
	}
}

int main()
{
	ifstream input("D:\\Temporary work data\\RadixSort1.txt");

	int n = Length(input);
	int* A = new int[n];

	//数据读入到A
	Read2A(input, A, n);
	int m = RadixNum(A[0]);

	int **Aux = new int *[n];
	for (int i = 0; i != n; i++)
		Aux[i] = new int[m];
	//按位分别读入到Aux
	Change2Radix(A, Aux, n, m);

	//从最低位到最高位分别Counting Sort
	for (int i = m - 1; i >= 0; i--)
		CountingSort(Aux, n, m, i);

	//输出结果
	for (int i = 0; i != n; i++) {
		for (int j = 0; j != m; j++) {
			cout << Aux[i][j];
		}
		cout << endl;
	}
	delete[]A,Aux;
	return 0;
}
