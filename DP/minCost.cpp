//Scritto di gennaio 2025
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int par(vector<int> &cost, int i, int cut, vector<vector<int>> &memo){
    if(cut - i <= 1) {
        return 0;
    }

    if(memo[i][cut] != -1){
        return memo[i][cut];
    }

    int minSoFar = INT_MAX;
    int length = cost[cut] - cost[i];

    for(int k = i+1; k < cut; k++){
        int val = length + par(cost, i, k, memo) + par(cost, k, cut, memo);

        minSoFar = min(minSoFar, val);
    }

    return memo[i][cut] = minSoFar;

}

int parHelper(vector<int> &cost){
    int i = 0;
    int cut = cost.size();
    vector<vector<int>> memo (cut , vector<int> (cut, -1));
    return par(cost, i, cut-1, memo);
}

int main(){
    vector<int> cost = {0,2,20,25,30};
    cout<<parHelper(cost)<<endl;
}