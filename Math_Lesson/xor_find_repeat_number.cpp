/*
 *  加餐二的思考题: 在1到n的数字中，有且只有一个m数字重复了，其他的数字只出现一次，找出这个数字
 *  使用异或的特性: 
 *  a = 1^2..^m..^n
 *  b = 1^2..^m^m..^n
 *  a^b = (1^2..^m..^n)^(1^2..^m..^n)^m = 0 ^ m = m
 *  也可以使用排序，bitset，hash等方法
 */
#include <iostream>
#include <random>

using namespace std;

int find_repeat(int a[], int length)
{
    int result = a[0];
    for(int i=1; i<= length;i++){   // 求数组所有异或值
        result ^= a[i];
    }
    int result_2 = 1;
    for(int i=2;i<=length;i++){ // 计算所有1-n的异或值
        result_2 ^= i;
    }
    return result ^ result_2;   //得到重复的值

}

int main ()
{
    std::default_random_engine random;  // 使用随机数
    int length = random () % 100;
    int repeat = random () % 100;

    if (length == 0 ) {
        length = 10;
    }
    if (length < repeat) {  // length 比repeat 大
        length = length ^ repeat;
        repeat = length ^ repeat;
        length = length ^ repeat;
    }

    int array[length+1];
    for(int i = 0,j=1;i <length+1; i++,j++) {
        array[i] = j;
        if (i ==repeat-1) {
            j--;
        }
        
    } 
    cout<< "length:"<<length<<endl;
    cout<< "repeat:"<<repeat<<endl;
    for(int i =0; i< length+1; i++){
        cout<< array[i]<<' ';
    }
    cout<<endl;
    cout<<"repeat number:"<<find_repeat(array,length)<<endl;



}