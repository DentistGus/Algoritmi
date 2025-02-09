#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int par(vector<int> &c, int i, int j, vector<vector<int>> &memo){
    if(i+1 == j) {
        return 0;
    }

    if(memo[i][j] != -1){
        return memo[i][j];
    }

    int minSoFar = INT_MAX;
    
    for(int k = i+1; k < j; k++){
        int val = par(c, i, k, memo) + par(c, k, j, memo) + c[i]*c[k]*c[j];

        if(val < minSoFar){
            minSoFar = val;
            memo[i][j] = val;
        }
    }

    return minSoFar;

}

int parHelper(vector<int> &c){
    int i = 0;
    int j = c.size();
    vector<vector<int>> memo (j , vector<int> (j, -1));
    return par(c, i, j-1, memo);
}

int main(){
    vector<int> c = {1,2,3,4,3};
    cout<<parHelper(c)<<endl;
}