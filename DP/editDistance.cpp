#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int editDist(string &s1, string &s2, int m, int n, vector<vector<int>> &memo){

    if(m == 0) return n;

    if(n == 0) return m;

    if(memo[m][n] != -1){
        return memo[m][n];
    }

    if(s1[m-1] == s2[n-1]) memo[m][n] = editDist(s1, s2, m-1, n-1, memo);

    else{
        memo[m][n] = 1 + min({editDist(s1, s2, m, n-1, memo),
                              editDist(s1, s2, m-1, n, memo),
                              editDist(s1, s2, m-1, n-1, memo)});
    }

    return memo[m][n];

}

int editDistance(string &s1, string &s2){
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> memo (m + 1, vector<int> (n + 1, -1));
    return editDist(s1, s2, m, n, memo);
}

int main(){
    string s1 = "geek";
    string s2 = "gesek";
    cout<<editDistance(s1, s2)<<endl;
}

