#include <iostream>
#include <vector>

using namespace std;

bool subsetSum(vector<int> &arr, int n, int sum, vector<vector<int>> &memo){

    if(sum == 0) return true;
    if(n <= 0) return false;

    if (memo[n][sum] != -1) return memo[n][sum];

    if(arr[n-1] > sum){
        return memo[n][sum] = subsetSum(arr, n-1, sum, memo);
    }

    else{
        return memo[n][sum] = subsetSum(arr, n-1, sum, memo) || subsetSum(arr, n-1, sum-arr[n-1], memo);
    }

}

void findSum(vector<int> &arr, int sum){
    int n = arr.size();
    vector<vector<int>> memo(n + 1, vector<int>(sum + 1, -1));
    if(subsetSum(arr, n,sum, memo)) cout<<"True"<<endl;
    else cout<<"False"<<endl;

    for(int i = 0; i < n + 1; i++){
        for(int j = 0; j < sum + 1; j++){
            cout<<memo[i][j]<<" ";
        }
        cout<<endl;
    }

}

int main(){
    vector<int> arr = {3,34,4,12,5,2};
    int sum = 9;
    findSum(arr, sum);
}