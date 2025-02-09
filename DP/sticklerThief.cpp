#include <iostream>
#include <vector>

using namespace std;

int findMaxSum(int i, vector<int> &arr, vector<int> &memo){
    if(i >= arr.size()){
        return 0;
    }

    if(memo[i] != -1){
        return memo[i];
    }

    int take = max(arr[i] + findMaxSum(i+2, arr, memo), findMaxSum(i+1, arr, memo));

    memo[i] = take;

    return memo[i];

}

int findMaxSumHelper(vector<int> &arr){
    int i = 0;
    vector<int> memo (arr.size(), -1);
    return findMaxSum(i, arr, memo);
}

int main(){
    vector<int> arr1 = {6,5,5,7,4};
    cout<<findMaxSumHelper(arr1)<<endl;

    vector<int> arr2 = {1,5,3};
    cout<<findMaxSumHelper(arr2)<<endl;

    vector<int> arr3 = {4,4,4,4};
    cout<<findMaxSumHelper(arr3)<<endl;
}