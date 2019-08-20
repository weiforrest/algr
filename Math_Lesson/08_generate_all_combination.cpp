/*
 * 生成全组合
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

char code[] = "abcde";

void print_result(vector<string> &result)
{
	static int num = 1;
	vector<string>::iterator i= result.begin();
	while(i!=result.end()){
		cout<<"result"<<num++<<": "<<(*i++)<<endl;
	}
}


void generate_combination(string todo,vector<string> &result)
{
  if(todo.length() == 0) {
    return ;
  }
  else if( todo.length() == 1) {
    result.push_back(todo.substr(0,1));
    result.push_back(string(" "));
    print_result(result);
  }else{
    char current = todo.front();
    generate_combination(todo.substr(1), result);
    vector<string> pre;
    pre.assign(result.begin(),result.end());
    vector<string>::iterator i = result.begin();
    while(i != result.end()) {
      (*i++).append(1,current);
    }
    print_result(result);
    for(i=pre.begin();i!=pre.end();i++){
      result.push_back(*i);
    }
  }
}

int main()
{
vector<string> result;
generate_combination("12345",result);
return 0;
}
