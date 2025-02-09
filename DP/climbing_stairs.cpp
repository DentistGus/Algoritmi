#include <iostream>
#include <vector>

using namespace std;

vector<int> memo;

int climbStairs(int n){
    if(n<=1) return 1;
    if(memo[n] != -1) return memo[n];
    memo[n] = climbStairs(n-1)+climbStairs(n-2);
    return memo[n];
}

int main(){
    int n;
    n = 4;
    memo.resize(n+1, -1);
    cout<<climbStairs(n)<<endl;
    return 0;
}
