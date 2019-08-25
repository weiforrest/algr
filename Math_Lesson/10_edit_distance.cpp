#include<iostream>
#include<string>
using namespace std;

int min(int a,int b,int c)
{
  int tmp = a>b ? b: a;
  return tmp>c ? c:tmp;
}

void print_result(int *d,int len_a,int len_b)
{
  for(int i=0;i<len_a+1;i++) {
    for(int j=0;j<len_b+1;j++) {
      cout<<"d["<<i<<"]["<<j<<"]:"<<*(d+i*(len_b+1)+j)<<" ";
    }
    cout<<endl;
  }
}

int getDistance(string a, string b)
{
  int len_a = a.length();
  int len_b = b.length();
  int d[len_a+1][len_b+1];
  for(int i=0; i< len_a+1; i++) {
    d[i][0] = i;
  }
  for(int j=1; j< len_b+1; j++) {
    d[0][j] = j;
  }
  for(int i=1;i<len_a+1;i++) {
    for(int j=1;j<len_b+1;j++) {
      d[i][j] = min(d[i-1][j]+1,d[i][j-1]+1,d[i-1][j-1]+(a[i-1] ==b[j-1] ? 0:1));
    }
  }
  print_result((int*)d,len_a,len_b);

  return d[len_a][len_b];
}

int main()
{
  string a,b;
  while(cin>>a>>b){
    cout<<"the distance is: "<<getDistance(a,b)<<endl;
  }
  return 0;
}

  
