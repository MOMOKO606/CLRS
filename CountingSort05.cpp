#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

int Length(ifstream &input)
{
	if (!input.is_open())
		cout << "Error in opening file!" << endl;

	double x;
	int n = 0;

	while (!input.eof()) {
		input >> x;
		n++;
	}
	return n - 1;
}

template<class T>
void Read2A(ifstream &input,int n,T *A)
{
	input.clear();
	input.seekg(0, ios::beg);

	for (int i = 0; i != n; i++)
		input >> A[i];

}

template<class T>
T GetMax(T *A, int n)
{
	T max = -INFINITY;
	for (int i = 0; i != n; i++) {
		if (A[i] > max)
			max = A[i];
	}
	return max;
}

template<class T>
void CountingSort(T* A,int n)
{
	double max = GetMax(A, n);
	int m = (int)max;

	T* B = new T[m];
	for (int i = 0; i <= m; i++)
		B[i] = 0;
	for (int i = 0; i != n; i++) {
		int p = (int)A[i];
		B[p] += 1;
	}
	int j = 0;
	for (int i = 0; i <= m; i++) {
		while (B[i] != 0) {
			A[j] = i;
			j++;
			B[i] += -1;
		}
	}

}

int main()
{
	ifstream input("D:\\Temporary work data\\CountingSort Test.txt");
	int n = Length(input);

	double* A = new double[n];
	Read2A(input, n, A);

	CountingSort(A, n);

	for (int i = 0; i != n; i++)
		cout << A[i] << endl;

	delete[] A;

	return 0;
}
