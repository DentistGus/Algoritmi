#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int jumpGame(vector<int> &arr, int n, int j, vector<int> &memo){
    if(j == 0){
        return 0;
    }

    if(memo[n] != -1) return memo[n];

    for(int j = n-1; j >= 0; j--){
        if(arr[j] < n-j){
           memo[n] = INT_MAX;
        }
        else{
            memo[n] = min(memo[n], 1 + jumpGame(arr, n-1, n-j, memo));
        }
    }

    return memo[n];

}

int jumpGameHelper(vector<int> &arr){
    int n = arr.size();
    vector<int> memo (n + 1, -1);
    int ans = jumpGame(arr, n-1, n-1, memo);

    if(ans == INT_MAX){
        cout<<"a"<<endl;
        return -1;
    }
    
     return ans;

}

int main(){
    vector<int> arr = {1,3,5,8,9,2,6,7,6,8,9};
    cout<<jumpGameHelper(arr)<<endl;
}