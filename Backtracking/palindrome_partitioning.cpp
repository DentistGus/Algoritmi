#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

bool check_palindrome(string s, int left, int right){
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

void backtrack(vector<vector<string>>& output, vector<string>& part, string s, int index){
    if(index>=s.size()){
        output.push_back(part);
        return;
    }

    for(int i = index; i < s.size(); i++){
        if(check_palindrome(s, index, i)){
            part.push_back(s.substr(index, i - index + 1)); 
            backtrack(output, part, s, i+1);
            part.pop_back();
        }
    }
}

vector<vector<string>> partition(string s){
    vector<vector<string>> output;
    vector<string> part;
    backtrack(output, part, s, 0);
    return output;
}

int main(){
    string s = "anna";
    vector<vector<string>> result = partition(s);
    for(int i = 0; i < result.size(); i++){
        for (int j = 0; j < result[i].size(); j++){
            cout<<result[i][j]<<", ";
        }
    }
}