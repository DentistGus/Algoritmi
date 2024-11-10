/*Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Constraints:
1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.*/

#include <iostream>
#include <vector>

using namespace std;

void backtrack(vector<int>& nums, vector<vector<int>>& output, int start){

    if (start == nums.size()) {
        cout<<"OK"<<endl;
        output.push_back(nums);  // Raggiunto una permutazione completa
        return;
    }
    for(int i=start; i<nums.size(); i++){
        swap(nums[start], nums[i]);
        backtrack(nums, output, start+1);
        //In questo swap faccio in pratica swap(nums[2], nums[2])
        swap(nums[start], nums[i]);
        //Dopo la prima permutazione {1, 2, 3}, il ciclo al livello start = 1 continua e scambia nums[1] con nums[2], generando {1, 3, 2}.
    }  
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> output;
    backtrack(nums, output, 0);
    return output;
}

int main(){
    vector<int> nums={1,2,3};

    vector<vector<int>> result = permute(nums);
    cout<<"[";
    for(int i=0; i<result.size(); i++){
        cout<<"[";
        for(int j=0; j<result[i].size(); j++){
            cout<<result[i][j]<<",";
        }
        cout<<"]";
    }
    cout<<"]"<<endl;
}