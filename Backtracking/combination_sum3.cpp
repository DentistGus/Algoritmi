//Soluzione accettata da leetcode tuttavia è di gran lunga migliorabile (batte solo il 7% di tutte le soluzioni per quanto riguarda il runtime)

#include <iostream>
#include <vector>

using namespace std;

bool is_solution(vector<int>& vec, int n){
    int sum=0;
    for(int i = 0; i<vec.size(); i++){
        sum += vec[i];
    }
    if(sum == n) return true;
    else return false;
}

bool is_safe(vector<int>& vec){
    int begin=vec[0];
    for(int i = 0; i<vec.size()-1; i++){
        if(vec[i+1] > begin){
            begin=vec[i+1];
        }
        else return false;
    }
    return true;
}

void backtrack(vector<vector<int>>& result, vector<int>& vec, int k, int n, int index){
    if(is_solution(vec, n) && vec.size()==k && is_safe(vec)){
        result.push_back(vec);
        return;
    }
    if(vec.size()<k){
        for(int i = index; i<10; i++){
            vec.push_back(i);
            backtrack(result, vec, k, n, index+1);
            vec.pop_back();
        }
    } 
    return;
}

vector<vector<int>> combinationSum3(int k, int n){
    vector<vector<int>> result;
    vector<int> vec;
    int index = 1;
    backtrack(result, vec, k, n, index);
    return result;
}

int main (){
    int k=3;
    int n=9;
    vector<vector<int>> output = combinationSum3(k, n);

    for(int i = 0; i<output.size(); i++){
        for(int j = 0; j<output[i].size(); j++){
            cout<<output[i][j];
        }
        cout<<endl;
    }
}