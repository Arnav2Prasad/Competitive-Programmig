#include <iostream>
#include <vector>
using namespace std;


void reverseArray(vector<int> &arr , int m){
    int temp = 0;
    int start = m+1;
    int end = arr.size()-1;
    while (start < end){
        temp = arr[start];
        arr[start] =arr[end];
        arr[end]= temp;
        start++;
        end--;
    }

}
