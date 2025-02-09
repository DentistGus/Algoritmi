#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int goldMine(int row, int col, vector<vector<int>> &mat, vector<vector<int>> &memo){
    if(row < 0 || row == mat.size()){
        return 0;
    }

    if(col == mat[row].size()){
        return 0;
    }

    if(memo[row][col] != -1){
        return memo[row][col];
    }

    int currentMax = INT_MIN;

    currentMax = max(currentMax, mat[row][col] + max(max(goldMine(row+1, col+1, mat, memo), goldMine(row, col+1, mat, memo)), goldMine(row-1, col+1, mat, memo)));
    
    memo[row][col] = currentMax;

    return memo[row][col];

}

int goldMineHelper(vector<vector<int>> &mat){
    int row = 0;
    int col = 0;
    vector<vector<int>> memo (mat.size(), vector<int> (mat[row].size(), -1));

    int currentMax = INT_MIN;

    //for che mi serve per partire da una riga qualsiasi della matrice, senza tale for partirei sempre dalla cella [0][0]...
    for(int i = 0; i <mat.size(); i++){
        currentMax = max(currentMax, goldMine(i, 0, mat, memo));
    }

    return currentMax;
}

int main(){
    vector<vector<int>> mat1 = {{1,3,3},{2,1,4},{0,6,4}};
    cout<<goldMineHelper(mat1)<<endl;

    vector<vector<int>> mat2 = {{1,3,1,5},{2,2,4,1},{5,0,2,3},{0,6,1,2}};
    cout<<goldMineHelper(mat2)<<endl;

    vector<vector<int>>  mat3 = {{1,3,3},{2,1,4},{0,7,5}};
    cout<<goldMineHelper(mat3)<<endl;
}