#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <bits/stdc++.h>

using namespace std;

int lis(int i, int j, vector<int> &arr, vector<vector<int>> &memo){
    if(i == arr.size()){
        return 0;
    }

    if(memo[i][j+1] != -1){
        return memo[i][j+1];
    }

    int take = 0;
    int no_take = 0;

    if(arr[j] < arr[i] || j == -1){
        take = 1 + lis(i+1, i, arr, memo);
    }

    no_take = lis(i+1, j, arr, memo);
    
    memo[i][j+1] = max(take, no_take);

    return memo[i][j+1];
}

int lisHelper(vector<int> &arr){
    int i = 0;
    int j = -1;
    vector<vector<int>> memo (arr.size(), vector<int> (arr.size(), -1));
    return lis(i, j, arr, memo);
}

int main(){
    vector<int> arr1 = {5,8,3,7,9,1};
    cout<<lisHelper(arr1)<<endl;

    vector<int> arr2 = {0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};
    cout<<lisHelper(arr2)<<endl;

    vector<int> arr3 = {3,10,2,1,20};
    cout<<lisHelper(arr3)<<endl;
}