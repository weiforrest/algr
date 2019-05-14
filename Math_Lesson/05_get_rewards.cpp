/*
 * 程序员的数学基础课 第五讲 递归 
 * 奖赏的所有种类
*/
#include <iostream>
#include <vector>
using namespace std;


int rewards[] = {1, 2, 5, 10};

void print_result(vector<int> result)
{
    vector<int>::iterator i = result.begin();
    while(i != result.end()){
        cout << (*i++) <<" ";
    }
    cout<<endl;
}

void get(int sum, vector<int> result)
{
    if (sum == 0){
        print_result(result);
        return ;
    } else if(sum < 0){
        return;
    }else{
        for(int i = 0; i < 4; i++){
            vector<int> newresult;
            newresult.assign(result.begin(), result.end());
            newresult.push_back(rewards[i]);
            get(sum - rewards[i], newresult);
        }
    }


}

int main()
{
    vector<int> result;
    get(10, result);

    return 0;
}