//CLRS P41,Problems 2-4:Inversions

#include<string>
#include<iostream>
#include<fstream>
#include<math.h>
#include<limits>

using namespace std;

int Length(ifstream &input)
{
	if (!input.is_open())
		cout << "Error in opening file!";

	double x;
	int n = 0;

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

	for (int i = 0; i != n; i++)
		input >> A[i];
}

template<class T>
int Merge(T *A, int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	T *L = new T[n1 + 1];
	T *R = new T[n2 + 1];
	for (int i = p; i <= q; i++)
		L[i - p] = A[i];
	for (int i = q + 1; i <= r; i++)
		R[i - q - 1] = A[i];
	L[n1] = (numeric_limits<T>::max)();
	R[n2] = (numeric_limits<T>::max)();
	int i = 0;
	int j = 0;
	int sum = 0;
	for (int k = p; k <= r; k++) {
		if (L[i] <= R[j])
			A[k] = L[i++];
		else {
			A[k] = R[j++];
			if (n1 != i)
				sum += n1 - i;
		}
	}
	return sum;
}

template<class T>
int Get_Inversion(T *A, int p, int r)
{
	if (p == r)
		return 0;
	int q = floor((p + r - 1) / 2);
	return Get_Inversion(A, p, q) + Get_Inversion(A, q + 1, r) + Merge(A, p, q, r);
}

int main()
{
	ifstream input("D:\\Temporary work data\\test2.txt");
	int n = Length(input);

	double *A = new double[n];
	Read2A(input, A, n);

	int inver = Get_Inversion(A, 0, n - 1);

	cout << "# of inversion is " << inver << endl;
	for (int i = 0; i != n; i++)
		cout << A[i] << endl;

	delete[]A;

	return 0;
}
