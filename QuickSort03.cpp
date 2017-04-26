//CLRS P174,Exercises 7.1-2: Quicksort

#include<string>
#include<fstream>
#include<iostream>

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
void Exchange(T &x, T &y)
{
	T temp = x;
	x = y;
	y = temp;
}

template<class T>
int Partition(T *A, int p, int r)
{
	T pivot = A[r];
	int j = p - 1;
	int flag = 1;
	for (int i = p; i <= r - 1; i++) {
		if (A[i] < pivot)
			Exchange(A[i], A[++j]);
		else if (A[i] == pivot) {
			if(flag ==1)
				Exchange(A[i], A[++j]);
			flag *= -1;
		}
	}
	Exchange(A[++j], A[r]);
	return j;
}


template<class T>
void Quicksort(T *A, int p, int r)
{
	if (p < r) {
		int q = Partition(A, p, r);
		Quicksort(A, p, q - 1);
		Quicksort(A, q + 1, r);
	}
}


int main()
{
	ifstream input("D:\\Temporary work data\\Sort Test 1.txt");

	int n = Length(input);

	double *A = new double[n];
	Read2A(input, A, n);

	Quicksort(A, 0, n - 1);

	for (int i = 0; i != n; i++)
		cout << A[i] << endl;

	delete[] A;
	return 0;
}
