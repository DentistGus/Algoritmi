#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int lcs(int s1_size, int s2_size, string s1, string s2, vector<vector<int>> &memo){
    if(s1_size == 0 || s2_size == 0){
        return 0;
    }

    if(memo[s1_size][s2_size] != -1){
        return memo[s1_size][s2_size];
    }

    else{
        if(s1[s1_size] == s2[s2_size]){
            memo[s1_size][s2_size] = lcs(s1_size-1, s2_size-1, s1, s2, memo) + 1;
        }
        else{
            memo[s1_size][s2_size] = max(lcs(s1_size, s2_size-1, s1, s2, memo), lcs(s1_size-1, s2_size, s1, s2, memo));
        }
    }

    return memo[s1_size][s2_size];

}

int lcs_helper(string s1, string s2){
    vector<vector<int>> memo (s1.size()+1, vector<int> (s2.size()+1, -1));
    return lcs(s1.size(), s2.size(), s1, s2, memo);
}

int main(){
    string s1 = "ABCDGH";
    string s2 = "AEDFHR";
    cout<<s1[6]<<endl;
    cout<<lcs_helper(s1, s2)<<endl;

    string s3 = "ABC";
    string s4 = "AC";
    cout<<lcs_helper(s3, s4)<<endl;

    string s5 = "XYZW";
    string s6 = "XYWZ";
    cout<<lcs_helper(s5, s6)<<endl;

}