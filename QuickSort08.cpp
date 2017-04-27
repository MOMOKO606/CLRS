//CLRS P188,Problems 7-5:Quicksort
//Using Median-of-3 Partition

#include<string>
#include<iostream>
#include<fstream>

using namespace std;

int Length(ifstream &input)
{
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
void Read2A(ifstream &input, int n, T *A)
{
	input.clear();
	input.seekg(0, ios::beg);

	for (int i = 0; i != n; i++)
		input >> A[i];
}

template<class T>
void Exchange(T &x, T &y)
{
	T temp = x;
	x = y;
	y = temp;
}

template<class T>
int Partition_mof3(T *A, int p, int r)
{
	int X[3];
	for (int i = 0; i != 3; i++)
		X[i] = rand() % (r - p + 1) + p;
	if (X[0] >= X[1] && X[0] <= X[2])
		Exchange(A[X[0]], A[r]);
	else if (X[1] >= X[0] && X[1] <= X[2])
		Exchange(A[X[1]], A[r]);
	else
		Exchange(A[X[2]], A[r]);
	return Partition(A, p, r);
}

template<class T>
int Partition(T *A, int p, int r)
{
	T pivot = A[r];
	int j = p - 1;
	for (int i = p; i <= r - 1; i++) {
		if (A[i] <= pivot)
			Exchange(A[i], A[++j]);
	}
	Exchange(A[++j], A[r]);
	return j;
}

template<class T>
void QuickSort(T *A, int p, int r)
{
	if (p < r) {
		int q = Partition_mof3(A, p, r);
		QuickSort(A, p, q - 1);
		QuickSort(A, q + 1, r);
	}
}

int main()
{
	ifstream input("D:\\Temporary work data\\Sort Test 3.txt");
	int n = Length(input);

	double *A = new double[n];
	Read2A(input, n, A);

	QuickSort(A, 0, n - 1);

	for (int i = 0; i != n; i++)
		cout << A[i] << endl;
	delete[]A;
	return 0;
}
