#include <iostream>
#include <vector>
 using namespace std;

char code[] = "abcde";

void print_result(vector<char> &result)
{
	static int num = 1;
	cout<<"result "<<num++<<" :";
	vector<char>::iterator i= result.begin();
	while(i!=result.end()){
		cout<<(*i++)<<' ';
	}
	cout<<endl;
}


void break_code(int length,vector<char> &result)
{
	if(length <= 0) {
		print_result(result);
	}else {
		for(int i=0;i<5;i++){
			vector<char> new_result;
			new_result.assign(result.begin(),result.end());
			new_result.push_back(code[i]);
			break_code(length-1,new_result);

		}
	}
}

int main()
{
int length=4;
vector<char> result;
break_code(length,result);
return 0;
}
