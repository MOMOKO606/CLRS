// Counting sort for indices of non-negative numbers.
#include<string>
#include<iostream>
#include<fstream>

using namespace std;

int Length(ifstream &input)
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
T GetMax(T *A,int n)
{
	T max = A[0];
	for (int i = 1; i < n; i++) {
		if (A[i] > max)
			max = A[i];
	}
	return max;
}

template<class T>
void CountingSort(T *A, int n)
{
	T Amax = GetMax(A, n);
	int m = (int)Amax;

	T *C = new T[n];
	T *B = new T[m + 1];

	for (int i = 0; i <= m; i++)
		B[i] = 0;
	for (int i = 0; i < n; i++) {
		int a = (int)A[i];
		B[a] += 1;
	}
	for (int i = 1; i <= m; i++)
		B[i] += B[i - 1];
	for (int i = n - 1; i >= 0; i--) {
		int a = (int)A[i];
		int b = (int)B[a];
		C[b - 1] = (T)i;
		B[a] -= 1;
	}
	for (int i = 0; i < n; i++)
		A[i] = C[i];
}


int main()
{
	ifstream input("D:\\Temporary work data\\CountingSort Test.txt");
	int n = Length(input);

	double *A = new double[n];
	Read2A(input, A, n);

	CountingSort(A, n);

	for (int i = 0; i < n; i++)
		cout << A[i] << endl;

	delete[] A;

	return 0;
}
