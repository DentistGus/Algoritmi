#include <iostream>
#include <vector>
#include <climits>
#include <bits/stdc++.h>

using namespace std;

int maximizeTheCuts(int n, int x, int y, int z, vector<int> &memo){
    if(n == 0){
        return 0;
    }

    if(n < 0){
        return -1;
    }

    if(memo[n] != -1){
        return memo[n];
    }

    int a = maximizeTheCuts(n-x, x, y, z, memo);
    int b = maximizeTheCuts(n-y, x, y, z, memo);
    int c = maximizeTheCuts(n-z, x, y, z, memo);

    int maxCut = max(a, max(b, c));

    if(maxCut == -1){
        return memo[n] = -1;
    }

    return memo[n] =  maxCut + 1;

}

int maximizeTheCutsHelper(int n, int x, int y, int z){
    int ans;
    //cout<<"Taglio minimo: "<<*min_element(cuts.begin(), cuts.end())<<endl;
    vector<int> memo (n+1, -1);
    ans = maximizeTheCuts(n, x, y, z, memo);
    if(ans == -1){
        return 0;
    }
    else return ans;
}

int main(){
    int n = 7;
    int x = 8;
    int y = 9;
    int z = 10;
    cout<<maximizeTheCutsHelper(n, x, y, z)<<endl;
}