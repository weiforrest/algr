/*
 * 程序员的数学基础课 第五讲 递归 
 * 分解 整数 n的乘积
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void print_result(vector<int> &result)
{
    vector<int>::iterator i = result.begin();
    while(i != result.end()){
        cout << (*i++) <<" ";
    }
    cout<<endl;
}

bool is_exist(vector <int> &result, int value)
{
    vector<int>::iterator i = find(result.begin(), result.end(),value);
    return (i == result.end()) ? false : true;
}

void resolve(int num, vector<int> &result)
{
    if (num == 1){
        print_result(result);
        return ;
    }else{
        for(int i = 1; i <= num; i++){
            if( num % i == 0) {
                if(!is_exist(result, i)) {
                    vector<int> newresult;
                    newresult.assign(result.begin(), result.end());
                    newresult.push_back(i);
                    // newresult.push_back(num /i);
                    resolve(num / i, newresult);
                }
            }
        }
    }


}

int main()
{
    vector<int> result;
    resolve(8, result);

    return 0;
}