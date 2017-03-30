#include <iostream>

using namespace std;

int main()
{
  //输入数组长度
  int n;
  cin>>n;

  //输入A数组
  double A[n];
  for (int i=0;i!=n;i++)
    cin>>A[i];

  //Insertion Sort
  for (int i=1;i!=n;i++){
    double key=A[i];
    int j=i-1;
    while(A[j]>key && j>=0){
      A[j+1]=A[j];
      --j;
    }
    A[j+1]=key;
  }

  //输出结果
  for(int i=0;i!=n;i++)
  cout<<A[i]<<endl;

  return 0;
}
