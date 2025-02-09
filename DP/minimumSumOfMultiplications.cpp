#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int sum(vector<int> &arr, int i, int j){
    int result = 0;
    for(int k = i; k <= j; k++){
        result = (result + arr[k]) % 100;
    }
    return result;
}

int minSum(vector<int> &arr, int i, int j, vector<vector<int>> &memo){
    if(i == j){
        return 0;
    }

    if(memo[i][j] != -1){
        return memo[i][j];
    }

    int minSoFar = INT_MAX;

    for(int k = i; k < j; k++){
        int val = minSum(arr, i, k, memo) + minSum(arr, k+1, j, memo) + (sum(arr, i, k) * sum(arr, k+1, j));

        minSoFar = min(minSoFar, val);
    }

    memo[i][j] = minSoFar;

    return memo[i][j];

}

int minSumHelper(vector<int> &arr){
    int i = 0;
    int j = arr.size();
    vector<vector<int>> memo (j, vector<int> (j,-1));
    return minSum(arr, i, j-1, memo);
}

int main(){
    vector<int> arr = {40,60,20};
    cout<<minSumHelper(arr)<<endl;
}