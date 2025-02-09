//Complessità: O(n^2)
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int lcs(int i, int j, string s1, string s2, vector<vector<int>> &memo){
    if(i == s1.size() || j == s2.size()){
        return 0;
    }

    if(memo[i][j] != -1){
        return memo[i][j];
    }

    int maxSoFar;

    if(s1[i] == s2[j]){
        maxSoFar = lcs(i+1, j+1, s1, s2, memo) + 1;
    }
    else{
        maxSoFar = max(lcs(i+1, j, s1, s2, memo), lcs(i, j+1, s1, s2, memo));
    }

    memo[i][j] = maxSoFar;

    return memo[i][j];

}

int lcsHelper(string s1, string s2){
    int s1Length = s1.size();
    int s2Length = s2.size();
    vector<vector<int>> memo (s1Length, vector<int> (s2Length, -1));
    return lcs(0, 0, s1, s2, memo);
}

int main(){
    string s1 = "abcd";
    string s2 = "acdb";
    string s3 = "dacb";
    cout<<lcsHelper(s1, s2)<<endl;
    cout<<lcsHelper(s1, s3)<<endl;
}