/*
 * 程序员的数学基础课 第六讲 递归 
 * 归并排序
 */
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

// 非原地合并
void merge(int arr1[],int length1, int arr2[], int length2)
{
    int  i = 0,j =0;
    vector <int> tmp;
    while( i < length1 && j < length2) {
        if(arr1[i] > arr2[j]) {
            tmp.push_back(arr2[j]);
            j++;
        }else {
            tmp.push_back(arr1[i]);
            i++;
        }
    }

    while(i < length1) {
        tmp.push_back(arr1[i++]);
    }
    while(j < length2) {
        tmp.push_back(arr2[j++]);
    }

    i=0;j=0;
    while(i< length1) {
        arr1[i++] = tmp[j++];
    }
    i=0;
    while(i<length2) {
        arr2[i++] = tmp[j++];
    }
}

void merge_sort(int arr[], int length)
{
    if(length <=1) return;
    int middle = length /2;
    merge_sort(arr, middle);
    merge_sort(arr+middle, length-middle);
    merge(arr,middle,arr+middle,length-middle);
}



int main()
{
    int length = 15;
    int arr[length];
    std::default_random_engine random;  // 使用随机数
    for(int i = 0; i< length; i++){
       arr[i] = random() % 100; 
    }
    for(int i =0; i< length; i++){
        cout<< arr[i]<<' ';
    }
    cout<<endl;
    merge_sort(arr,length);
    for(int i =0; i< length; i++){
        cout<< arr[i]<<' ';
    }
    cout<<endl;
}