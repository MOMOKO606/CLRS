#include<string>
#include<iostream>
#include<fstream>
#include<vector>
#include<math.h>;

using namespace std;

int Length4Str(ifstream &input)
{
	if (!input.is_open())
		cout << "Error in opening file!";

	input.clear();
	input.seekg(0, ios::beg);

	string temp;
	int m = 0;

	while (getline(input, temp, '\n')) {
		m++;
	}
	return m;
}

int Width4Str(ifstream &input)
{
	if (!input.is_open())
		cout << "Error in opening file!";

	input.clear();
	input.seekg(0, ios::beg);

	string temp;
	int n = -INFINITY;

	while (getline(input, temp, '\n')) {
		int p = temp.length();
		if (p > n)
			n = p;
	}
	return n;
}

template<class T>
void Read2A_Str_2D(ifstream &input, T *A, int m)
{
	input.clear();
	input.seekg(0, ios::beg);

	for (int i = 0; i < m; i++)
		input >> A[i];
}

void CountingSort4Str(char** S, int n, int st, int fsh, int col)
{
	//创建辅助数组B和C
	int* B = new int[174];
	char** C = new char*[fsh + 1];
	for (int i = 0; i != fsh + 1; i++)
		C[i] = new char[n];

	//Counting sort to the 1st letter of each string
	for (int i = 0; i != 173; i++)
		B[i] = 0;
	for (int i = st; i <= fsh; i++)
		//“+51”是因为C++的NaN ASCII值为-51
		B[(int)S[i][col]+51] += 1;
	for (int i = 1; i != 173; i++)
		B[i] += B[i - 1];
	for (int i = fsh; i >= st; i--) {
		for (int j = 0; j != n; j++)
			//“+(st-1)”是因为C数组index包含了0到st-1，纯粹为了定义方便
			C[st+B[(int)S[i][col]+51]-1][j] = S[i][j];
		B[(int)S[i][col]+51] -= 1;
	}

	//辅助数组C是首字母排序后的结果，将C复制到S中
	for (int i = st; i <= fsh; i++)
		for (int j = 0; j != n; j++)
			S[i][j] = C[i][j];
}

vector<int> SplitIndex(char** S, int st, int fsh, int col)
{
	vector<int> Aux;
	char letter_begin = S[st][col];
	for (int i = st; i <= fsh; i++) {
		char letter_end = S[i][col];
		if (letter_begin != letter_end) {
			Aux.push_back(i - 1);
			letter_begin = letter_end;
		}
	}
	return Aux;
}

void CountingString(char** S, int n, int st, int fsh, int col)
{
	//对字符串数组S排序
	//Step1.用counting sort排序S的第1列；
	//Step2.对排序好的每一段的第2列分别排序。

	//Base case
	if (st == fsh || col == n)
		return;

	CountingSort4Str(S, n, st, fsh, col);

	vector<int>Aux=SplitIndex(S, st, fsh, col);

	int l = Aux.size() - 1;
	int k = 0;

	int st_sub = st;
	int fsh_sub = Aux[k];

	while (st_sub <= fsh_sub) {
		CountingString(S, n, st_sub, fsh_sub, col + 1);

		st_sub = fsh_sub + 1;
		k == l ? fsh_sub = fsh : fsh_sub = Aux[++k];
	}
}

int main()
{
	ifstream input("D:\\Temporary work data\\CountingString.txt");

	int m = Length4Str(input);
	int n = Width4Str(input);

	char **A = new char *[m];
	for (int i = 0; i < m; i++)
		A[i] = new char[n + 1];

	Read2A_Str_2D(input, A, m);

	//Test
	//Show the original A
	for (int i = 0; i != m; i++)
		cout << A[i] << endl;

	cout << endl;

	CountingString(A, n, 0, m - 1, 0);

	//Test
	//Show the result
	cout << endl;
	for (int i = 0; i != m; i++) {
		for (int j = 0; j != n; j++)
			cout << A[i][j];
		cout << endl;
	}

	delete[]A;
	return 0;
}
