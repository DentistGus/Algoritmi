#include <iostream>
#include <climits>

using namespace std;

int minCost(int matrix[3][3], int m, int n, int memo[3][3]){

    memo[0][0] = matrix[0][0];

    if(memo[m][n] != -1) return memo[m][n];

    if(m < 0 || n < 0) return INT_MAX;

    memo[m][n] = matrix[m][n] + min(minCost(matrix, m-1, n, memo), min(minCost(matrix, m, n-1, memo), minCost(matrix, m-1, n-1, memo)));

    return memo[m][n];

}

int find_min_cost(int matrix[3][3], int m, int n){
    int memo[3][3];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            memo[i][j] = -1;
        }
    }
    return minCost(matrix, m-1, n-1, memo);
}

int main(){
    int m = 3;
    int n = 3;
    int matrix[3][3] = {{1,2,3},{4,8,2},{1,5,3}};
    cout<<find_min_cost(matrix, m, n)<<endl;
}