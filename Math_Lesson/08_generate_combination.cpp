/*
 * 生成组合
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;


void generate_combination(string todo,string &result,int length,int m)
{
  if(todo.length() == 0 || length == 0 ) {
    if(result.length() ==m)
    cout<<result<<endl;
    return ;
  }else{
    for(size_t i=0;i< todo.length();i++){
      string new_result;
      new_result.assign(result);
      new_result.push_back(todo[i]);
      string tmp = todo.substr(i+1);// 因为知道前面一定出现该组合，所以删除重复的
      generate_combination(tmp,new_result,length-1,m);
    }
  }
}

int main()
{
  string result;
  generate_combination("1234",result, 3,3);
  return 0;
}
