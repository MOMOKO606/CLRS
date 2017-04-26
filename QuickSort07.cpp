//CLRS P186,Problems 7-2:Quicksort
//Deal with equal element values.

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
int Partition(T *A, int p, int r, int &t)
{
	T pivot = A[p];
	int j = p;
	for (int i = p + 1; i <= r; i++) {
		if (A[i] <= pivot)
			Exchange(A[i], A[++j]);
	}
	Exchange(A[j], A[p]);
	t = j;
	j = p - 1;
	for (int i = p; i <= t - 1; i++) {
		if (A[i] < pivot)
			Exchange(A[i], A[++j]);
	}
	return j;
}

template<class T>
void QuickSort(T *A, int p, int r)
{
	if (p < r) {
		int t;
		int q = Partition(A, p, r, t);
		QuickSort(A, p, q);
		QuickSort(A, t + 1, r);
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
	return 0;
}
