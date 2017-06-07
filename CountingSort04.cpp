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
int Counta2b(T *A, int n, int a, int b)
{
	T max = GetMax(A, n);
	int m =(int)( max + 1);
	T *B = new T[m];

	for (int i = 0; i != m; i++)
		B[i] = 0;
	for (int i = 0; i != n; i++)
		B[A[i]] += 1;

	int sum = 0;
	for (int i = a; i <= b; i++)
		sum += B[i];

	return sum;
}

int main()
{
	ifstream input("D:\\Temporary work data\\CountingSort Test.txt");
	int n = Length(input);

	int *A = new int[n];
	Read2A(input, A, n);

	int a = 1;
	int b = 3;

	int sum = Counta2b(A, n, a, b);

	cout << sum << endl;
	delete[] A;
	return 0;
}
