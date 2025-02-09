//ERRATO
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int mps(vector<int> &arr, int i, int j, vector<vector<int>> &memo){
    if(i == j){
        return 0;
    }

    if(memo[i][j] != -1){
        return memo[i][j];
    }

    int maxProd = INT_MIN;
    int prod = 1;

    for(int k = j; k >= i; k--){
        prod *= arr[k];
        if(prod > maxProd){
            maxProd = prod;
            memo[i][j] = prod;
        }
    }
    
    return maxProd;

}

int mpsHelper(vector<int> &arr){
    int i = 0;
    int j = arr.size()-1;
    int n = arr.size();
    vector<vector<int>> memo (n, vector<int> (n, -1));
    return mps(arr, i, j, memo);
}

int main(){
    vector<int> arr = {-2,6,-3,-10,0,2};
    cout<<mpsHelper(arr)<<endl;
}