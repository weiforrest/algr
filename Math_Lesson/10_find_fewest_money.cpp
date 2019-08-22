/*
 * 程序员的数学基础课第十节思考题
 * 根据给定的硬币面值，计算最少硬币个数
 *
 */

#include <iostream>
#include <vector>

using namespace std;

int min(int *d, int length)
{
  int min = *d;
  bool find = false;
  for(int i=1;i<length;i++){
        if(min > *(d+i)) {
          min = *(d+i);
        }
  }
  return min;
}


void print_result(int * d,int rows, int cols, int *f)
{
  for(int i = 0; i< rows;i++) {
    cout<<i+1<<"  ";
    for(int j = 0; j< cols; j++) {
      cout<<*(d+i*cols+j)<<" ";
    }
    cout<<f[i];
    cout<<endl;
  }
  cout<<endl;
}

int find_few_money(vector<int> &coins, int money)
{
  int length = coins.size();
  int d[money][length];
  int f[money] ;
  for(int i=0;i<money;i++){
    for(int j=0;j<length;j++) {
      
      int coin = i+1;
        if(coins[j]> coin) { //当一枚当前面值的硬币表示不了时,使用一个极大值
          d[i][j] = money;
        } else if(coins[j] == coin){
          d[i][j] = 1;
        } else {
          if(f[coin-coins[j]-1] == money) {  //找不到等值的组合
            d[i][j] = money;
          }else{
            d[i][j] =f[coin-coins[j]-1]+1;
          }
        }
    }
    f[i] = min(d[i],coins.size());
  }
  print_result((int *)d,money,coins.size(),f);

  return  f[money-1];
}

int main()
{
  vector<int> coins = {2,3,7};
  int money = 100;

  int result = find_few_money(coins,money);
  return result;

}

