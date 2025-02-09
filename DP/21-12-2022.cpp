//Complessità: O(n^2) 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int militaryBase(vector<int> &sorted_Y, int prev_index, int curr_index, vector<vector<int>> &memo){
    if(curr_index == sorted_Y.size()){
        return 0;
    }

    if(memo[prev_index+1][curr_index] != -1){
        return memo[prev_index+1][curr_index];
    }

    int include = 0;

    if(prev_index == -1 || sorted_Y[curr_index] > sorted_Y[prev_index]){
        include = 1 + militaryBase(sorted_Y, curr_index, curr_index+1, memo);
    }

    int exclude = militaryBase(sorted_Y, prev_index, curr_index+1, memo);

    memo[prev_index+1][curr_index] = max(include, exclude);

    return memo[prev_index+1][curr_index];

}

int militaryBaseHelper(vector<int> &X, vector<int> &Y){
    int n = X.size();
    vector<pair<int, int>> pairs;

    for(int i = 0; i < n; i++){
        pairs.emplace_back(X[i], Y[i]);
    }

    sort(pairs.begin(), pairs.end());

    vector<int> sorted_Y;

    for(const auto &p : pairs){
        sorted_Y.push_back(p.second);
    }

    vector<vector<int>> memo (n, vector<int>  (n, -1));

    return militaryBase(sorted_Y, -1, 0, memo);

}

int main(){
    vector<int> X1 = {8,5,3,2};
    vector<int> Y1 = {3,4,7,6};
    cout<<militaryBaseHelper(X1 , Y1)<<endl;

    vector<int> X2 = {2,5,3,9,12,4};
    vector<int> Y2 = {1,7,2,4,3,10};
    cout<<militaryBaseHelper(X2 , Y2)<<endl;
}