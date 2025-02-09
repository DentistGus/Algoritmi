#include <iostream>
#include <vector>

using namespace std;

int coinChange(vector<int> &coins, int i, int sum, vector<vector<int>> &memo){
    if(sum == 0){
        return 0;
    }

    if(sum < 0 || i == coins.size()){
        return 1e9;
    }

    if(memo[i][sum] != -1){
        return memo[i][sum];
    }

    int take = 1e9;
    int notake;

    if(coins[i] <= sum){
        take = 1 + coinChange(coins, i, sum-coins[i], memo);
    }
    
    notake = coinChange(coins, i+1, sum, memo);

    memo[i][sum] = min(take, notake);

    return memo[i][sum];

}

int coinChangeHelper(vector<int> &coins, int sum){
    int i = 0;
    int n = coins.size();
    vector<vector<int>> memo (n, vector<int> (sum+1, -1));
    int ans = coinChange(coins, i, sum, memo);
    return ans == 1e9 ? -1 : ans;
}

int main(){
    vector<int> coins1 = {25,10,5};
    int sum1 = 30;
    cout<<coinChangeHelper(coins1, sum1)<<endl;

    vector<int> coins2 = {9,6,5,1};
    int sum2 = 19;
    cout<<coinChangeHelper(coins2, sum2)<<endl;

    vector<int> coins3 = {5,1};
    int sum3 = 0;
    cout<<coinChangeHelper(coins3, sum3)<<endl;

    vector<int> coins4 = {4,6,2};
    int sum4 = 5;
    cout<<coinChangeHelper(coins4, sum4)<<endl;


}