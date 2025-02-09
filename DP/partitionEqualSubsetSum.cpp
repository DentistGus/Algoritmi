#include <iostream>
#include <vector>

using namespace std;

int equalPartition(vector<int> &arr, int i, int sum, int temp, vector<vector<int>> &memo){
    if(i == arr.size()) return 0;
    if(temp > sum) return 0;
    if(temp == sum) return 1;
    if(memo[i][temp] != -1) return memo[i][temp];

    int include = equalPartition(arr, i+1, sum, temp+arr[i], memo);
    int exclude = equalPartition(arr, i+1, sum, temp, memo);

    return memo[i][temp] = (include || exclude);
}

bool equalPartitionHelper(vector<int> &arr){
    int i = 0;
    int sum = 0;
    int temp = 0;
    for(int j = 0; j < arr.size(); j++){
        sum += arr[j];
    }
    if(sum % 2 != 0) return false;
    sum = sum/2;
    vector<vector<int>> memo (arr.size()+1, vector<int> (sum+1, -1));
    return equalPartition(arr, i, sum, temp, memo);
}

int main(){
    vector<int> arr = {1,5,11,5};
    cout<<equalPartitionHelper(arr)<<endl;
}