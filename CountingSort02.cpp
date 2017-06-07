#include<string>
#include<iostream>
#include<fstream>
#include<math.h>
#include<stdlib.h>

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
T GetMax(T *A, int n)
{
	T max = -INFINITY;
	for (int i = 0; i < n; i++) {
		if (A[i] > max)
			max = A[i];
	}
	return max;
}

template<class T>
T GetMin(T *A, int n)
{
	T min = INFINITY;
	for (int i = 0; i < n; i++) {
		if (A[i] < min)
			min = A[i];
	}
	return min;
}

template<class T>
void CountingSort(T *A, int n)
{
	T max = GetMax(A, n);
	T min = GetMin(A, n);
	int m = (int)(max - min + 1);
	int q = (int)(abs(min));

	T *B = new T[m];
	T *C = new T[n];

	for (int i = 0; i < m; i++)
		B[i] = 0;
	for (int i = 0; i < n; i++) {
		int k = (int)(A[i] + q);
		B[k] += 1;
	}
	for (int i = 1; i < m; i++)
		B[i] += B[i - 1];
	for (int i = n - 1; i >= 0; i--) {
		int k = (int)(A[i] + q);
		int p = (int)(B[k]);
		C[p - 1] = A[i];
		B[k] -= 1;
	}
	for (int i = 0; i < n; i++)
		A[i] = C[i];
}

int main()
{
	ifstream input("D:\\Temporary work data\\CountingSort Test2.txt");
	int n = Length(input);

	double *A = new double[n];
	Read2A(input, A, n);

	CountingSort(A, n);

	for (int i = 0; i < n; i++)
		cout << A[i] << endl;
	delete[] A;

	return 0;
}
