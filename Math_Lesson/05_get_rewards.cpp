/*
 * 程序员的数学基础课 第五讲 递归 
 * 奖赏的所有种类
 * 
 * 使用递归保存所需要的中间状态和变量，减少编程时所需要负担的变量
 * 递归的核心思想和数学归纳法类似，将当前问题化为两部分：一个当前所需要解决的问题和另一个更简单的问题
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
    // 结束，得到满足条件的解。
    if (sum == 0){
        print_result(result);
        return ;
    } else if(sum < 0){ // 终止计算
        return;
    }else{  // 假设已知k=n-1的解，求k=n时的解
        for(int i = 0; i < 4; i++){
            vector<int> newresult;
            newresult.assign(result.begin(), result.end()); // 每一个新的结果都复制上一次的结果。
            newresult.push_back(rewards[i]);
            get(sum - rewards[i], newresult);   //k=n-1的解，留给嵌套
        }
    }


}

int main()
{
    vector<int> result;
    get(10, result);

    return 0;
}