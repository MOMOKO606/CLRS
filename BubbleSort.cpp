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
	input.seekg(0, ios::beg);

	for (int i = 0; i != n; i++)
		input >> A[i];
}

template<class T>
void Exchange(T &x,T &y)
{
	T temp=x;
	x = y;
	y = temp;
}

template<class T>
void OblCompExchange(T *A,int i, int j)
{
	if (A[i] > A[j])
		Exchange(A[i], A[j]);
}

template<class T>
void BubbleSort(T *A, int n)
{
	for (int i = 0; i != n - 2; i++) {
		for (int j = n - 1; j != i; j--) {
			OblCompExchange(A, j - 1, j);
		}
	}

}

int main()
{
	ifstream input("D:\\Temporary work data\\test.txt");
	int n = Length(input);

	double *A = new double[n];
	Read2A(input, A, n);

	BubbleSort(A, n);

	for (int i = 0; i != n; i++)
		cout << A[i] << endl;
	return 0;
}
