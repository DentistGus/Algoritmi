//scritto di gennaio 2025
//Complessità: O(n^3) siccome la matrice memo ha dimensione nxn, inoltre il ciclo for esegue altre O(n) operazioni per ogni stato della matrice memo.
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int dp_cutting_beam(vector<int> &cuts, int index, int n, vector<vector<int>> &memo){
    if(index+1 == n){
        return 0;
    }

    if(memo[index][n] != -1){
        return memo[index][n];
    }

    int minSoFar = INT_MAX;
    int length = cuts[n] - cuts[index];

    for(int k = index+1; k < n; k++){
        int cut = dp_cutting_beam(cuts, index, k, memo) + dp_cutting_beam(cuts, k, n, memo) + length;

        minSoFar = min(cut, minSoFar);
        memo[index][n] = minSoFar;

    }

    return memo[index][n];

}

int cutting_beam(int length, vector<int> &cuts){
    vector<int> new_cuts;
    new_cuts.push_back(0);

    for(int i = 0; i <cuts.size(); i++){
        new_cuts.push_back(cuts[i]);
    }

    new_cuts.push_back(length);

    int index = 0;
    int n = new_cuts.size();
    vector<vector<int>> memo (n, vector<int> (n, -1));
    return dp_cutting_beam(new_cuts, index, n-1, memo);
}

int main(){
    int length1 = 30;
    vector<int> cuts1 = {2,20,25};
    cout<<cutting_beam(length1, cuts1)<<endl;

    int length2 = 10;
    vector<int> cuts2 = {4,5,7,8};
    cout<<cutting_beam(length2, cuts2)<<endl;

    int length3 = 100;
    vector<int> cuts3 = {25,50,75};
    cout<<cutting_beam(length3, cuts3)<<endl;
}