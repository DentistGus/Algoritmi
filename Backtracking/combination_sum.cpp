/*Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. 
You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.*/

#include <iostream>
#include <vector>

using namespace std;

int check_target(vector<int>& combination){
    int sum=0;
    for(int i=0; i<combination.size(); i++){
        sum += combination[i];
    }
    return sum;
}

bool is_safe(vector<int>& combination){
    for (int i = 1; i < combination.size(); ++i) {
        if (combination[i - 1] > combination[i]) {
            return false; 
        }
    }
    return true; 
}

void backtrack(vector<int>& candidates, vector<int>& combination, vector<vector<int>>& output, int target){
    if(check_target(combination)==target && is_safe(combination)){
        output.push_back(combination);
        return;
    }
    for(int i=0; i<candidates.size(); i++){
        //cout<<i<<endl;
        if(check_target(combination)<=target){
            combination.push_back(candidates[i]);
            backtrack(candidates, combination, output, target);
            combination.pop_back();
        }      
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target){
    vector<vector<int>> output;
    vector<int> combination={};
    backtrack(candidates, combination, output, target);
    return output;
}

int main(){
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    vector<vector<int>> result = combinationSum(candidates, target);

    cout<<"[";
    for(int i=0; i<result.size(); i++){
        cout<<"[";
        for(int j=0; j<result[i].size(); j++){
            if(j==result[i].size()-1){
                cout<<result[i][j];
            }
            else cout<<result[i][j]<<",";
        }
        cout<<"]";
    }
    cout<<"]"<<endl;
}