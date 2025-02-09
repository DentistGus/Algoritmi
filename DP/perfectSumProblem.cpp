#include <iostream>
#include <vector>

using namespace std;

int psp(vector<int> &arr, int i, int target, vector<vector<int>> &memo){  
    if(target == 0){
        return 1;
    }

    if(i < 0){
        return 0;
    }

    if(memo[i][target] != -1){
        return memo[i][target];
    }

    int exclude = psp(arr, i-1, target, memo);

    // Includi l'elemento corrente (se possibile)
    int include = 0;
    if (arr[i] <= target) {
        include = psp(arr, i-1, target-arr[i], memo);
    }

    // Memorizza e restituisci il risultato
    return memo[i][target] = exclude + include;

}

int pspHelper(vector<int> &arr, int target){
    int i = arr.size()-1;
    vector<vector<int>> memo (arr.size(), vector<int> (target+1, -1));
    return psp(arr, i, target, memo);
}

int main(){
    vector<int> arr1 = {5,2,3,10,6,8};
    vector<int> arr2 = {2,5,1,4,3};
    vector<int> arr3 = {5,7,8};
    vector<int> arr4 = {35,2,8,22};
    int target1 = 10;
    int target2 = 3;
    int target3 = 0;
    cout<<pspHelper(arr1, target1)<<endl;
    cout<<pspHelper(arr2, target1)<<endl;
    cout<<pspHelper(arr3, target2)<<endl;
    cout<<pspHelper(arr4, target3)<<endl;

}