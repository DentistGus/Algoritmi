#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int knapsack(int capacity, vector<int> &val, vector<int> &wt, int i, vector<vector<int>> &memo){
    if(i>=val.size()){
        return 0;
    }

    if(memo[i][capacity] != -1) return memo[i][capacity];

    
    if(capacity >= wt[i]){
        memo[i][capacity] = max(val[i] + knapsack(capacity-wt[i], val, wt, i+1, memo), knapsack(capacity, val, wt, i+1, memo));
    }
    else{
        memo[i][capacity] = knapsack(capacity, val, wt, i+1, memo);
    }
    
    return memo[i][capacity];
}

int knapsackHelper(int capacity, vector<int> &val, vector<int> &wt){
    vector<vector<int>> memo (val.size(), vector<int>(capacity+1, -1));
    return knapsack(capacity, val, wt, 0, memo);
}

int main(){
    int capacity = 4;
    vector<int> val = {1,2,3};
    vector<int> wt = {4,5,1};
    cout<<knapsackHelper(capacity, val, wt)<<endl;
}