//Counting sort for non-nagetive numbers
#include<string>
#include<iostream>
#include<fstream>

using namespace std;

int Length( ifstream &input )
{
	if (!input.is_open())
		cout << "Error in opening file!";

	int n = 0;
	double x;
	while (!input.eof()) {
		input >> x;
		n++;
	}
	return n - 1;
}

template<class T>
void Read2A(ifstream &input, T *A, int n)
{
	input.clear();
	input.seekg(0, ios::beg);

	for (int i = 0; i < n; i++)
		input >> A[i];
}

template<class T>
T GetMax(T *A, int n)
{
	T m = A[0];
	for (int i = 1; i < n; i++) {
		if (A[i] > m)
			m = A[i];
	}
	return m;
}

template<class T>
void CountingSort(T *A, int n)
{
	double max = GetMax(A, n);
	int m = (int)max;

	double *B = new double[m + 1];
	double *C = new double[n];

	for (int i = 0; i <= m; i++)
		B[i] = 0;
	for (int i = 0; i < n; i++) {
		int x = (int)A[i];  //将index从double转为int
		B[x] += 1;
	}
	for (int i = 1; i <= m; i++)
		B[i] += B[i - 1];
	for (int i = n - 1; i >= 0; i--) {
		int a = (int)A[i];  //将index从double转为int
		int b = (int)B[a];  //将index从double转为int
		C[b - 1] = A[i];
		B[a] -= 1;
	}
	for (int i = 0; i < n; i++)
		A[i] = C[i];
}

int main()
{
	ifstream  input("D:\\Temporary work data\\CountingSort Test.txt");
	int n = Length(input);

	double *A = new double[n];
	Read2A(input, A, n);
	CountingSort(A, n);

	for (int i = 0; i < n; i++)
		cout << A[i] << endl;

	delete[] A;
	return 0;
}
