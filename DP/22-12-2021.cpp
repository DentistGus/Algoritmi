//Complessità: O(n^2)
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int longestPalindrome(int i, int j, string word, vector<vector<int>> memo){
    if(j < i || i > j){
        return 0;
    }

    if(i == j){
        return 1;
    }

    if(memo[i][j] != -1){
        return memo[i][j];
    }

    int longestPal;

    if((word[i] == word[j]) && (i != j)){
        longestPal = longestPalindrome(i+1, j-1, word, memo) + 2;
    }
    else{
        longestPal = max(longestPalindrome(i+1, j, word, memo), longestPalindrome(i, j-1, word, memo));
    }

    memo[i][j] = longestPal;

    return memo[i][j];

}

int longestPalindromeHelper(string word){
    vector<vector<int>> memo (word.size(), vector<int> (word.size(), -1));
    int i = 0;
    int j = word.size()-1;
    return longestPalindrome(i, j, word, memo);
}

int main(){
    string word1 = "ADAM"; //3
    string word2 = "MADAM"; //5
    cout<<longestPalindromeHelper(word1)<<endl;
    cout<<longestPalindromeHelper(word2)<<endl;

    string s1 = "aaaabbaa"; //6
    cout<<longestPalindromeHelper(s1)<<endl;

    string s2 = "abc"; //1
    cout<<longestPalindromeHelper(s2)<<endl;

    string s3 = "abacdfgdcaba"; //3 (aba)
    cout<<longestPalindromeHelper(s3)<<endl;
}