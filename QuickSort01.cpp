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
void Read2A(ifstream &input, T *A, int n)
{
	input.clear();
	input.seekg(ios::beg);

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
int Partition(T *A, int p, int r)
{
	T pivot = A[p];
	int j = p ;
	for (int i = p + 1; i <= r; i++) {
		if (A[i] <= pivot)
			Exchange(A[i], A[++j]);
	}
	Exchange(A[p], A[j]);
	return j;
}

template<class T>
void QuickSort(T *A, int p, int r)
{
	if (p < r) {
		int q = Partition(A, p, r);
		QuickSort(A, p, q - 1);
		QuickSort(A, q + 1, r);
	}
}

int main()
{
	ifstream input("D:\\Temporary work data\\Sort Test 1.txt");

	int n = Length(input);

	double *A = new double[n];
	Read2A(input, A, n);

	QuickSort(A, 0, n - 1);

	for (int i = 0; i != n; i++)
		cout << A[i] << endl;

	return 0;
}
