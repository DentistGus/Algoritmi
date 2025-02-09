#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <bits/stdc++.h> 

using namespace std;

int longestPalindrome(string &s, int i, int j, vector<vector<int>> &memo){
    if(i == j){
        return 1;
    }

    if(s[i] == s[j] && j == i + 1){
        return 2;
    }

    if(memo[i][j] != -1){
        return memo[i][j];
    }
    
    if(s[i] == s[j]){
        memo[i][j] = longestPalindrome(s, i+1, j-1, memo) + 2;
    }

    else{
        memo[i][j] = max(longestPalindrome(s, i+1, j, memo), longestPalindrome(s, i, j-1, memo));
    }

    return memo[i][j];

}

int longestPalindromeHelper(string &s){
    int i = 0;
    int j = s.size()-1;
    int n = s.size();
    vector<vector<int>> memo (n, vector<int> (n, -1));
    return longestPalindrome(s, i, j, memo);
}

int main(){
    string s1 = "aaaabbaa";
    cout<<longestPalindromeHelper(s1)<<endl;

    string s2 = "abc";
    cout<<longestPalindromeHelper(s2)<<endl;

    string s3 = "abacdfgdcaba";
    cout<<longestPalindromeHelper(s3)<<endl;

    string s4 = "ADAM";
    cout<<longestPalindromeHelper(s4)<<endl;

    string s5 = "MADAM";
    cout<<longestPalindromeHelper(s5)<<endl;
}

