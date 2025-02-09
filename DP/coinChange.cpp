//coinChange (Count Ways)
#include <iostream>
#include <vector>

using namespace std;

int coinChange(vector<int> &coins, int n, int sum, vector<vector<int>> &memo){

    if(sum == 0) return 1;
    if(sum < 0 || n == 0) return 0;

    if(memo[n - 1][sum] != -1) return memo[n - 1][sum];

    return memo[n - 1][sum] = coinChange(coins, n, sum - coins[n - 1], memo) + coinChange(coins, n - 1, sum, memo);

}

int findCoinChange(vector<int> &coins, int sum){
    int n = coins.size();
    vector<vector<int>> memo(n, vector<int>(sum + 1, -1));
    return coinChange(coins, n, sum, memo);
}

int main(){
    vector<int> coins = {25,10,5}; //25+5, 10+10+10, 5+5+5+5+5+5, 10+5+5+5+5, 10+10+5+5
    int sum = 30;
    cout<<findCoinChange(coins, sum)<<endl;
}