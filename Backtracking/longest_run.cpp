#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool is_safe(vector<vector<int>>& matrix, int row, int col){
    if(row >= 0 && row < matrix.size() && col >= 0 && col < matrix[0].size()){
        return true;
    }
    else{
        return false;
    }
}

int backtrack(vector<vector<int>>& matrix, int row, int col, vector<vector<int>>& longest_run){
    if(longest_run[row][col] != -1){
        return longest_run[row][col];
    }

    int max_lenght = 1;

    int directions[4][2] = {{0,1},{1,0},{0,-1},{-1,0}}; //rispettivamente dx, sotto, sx, sopra
    for(int i = 0; i < 4; i++){
        int new_row = row + directions[i][0];
        int new_col = col + directions[i][1];
        if(is_safe(matrix, new_row, new_col) && matrix[new_row][new_col] < matrix[row][col]){
            max_lenght = max(max_lenght, 1 + backtrack(matrix, new_row, new_col, longest_run));
        }  
    }
    longest_run[row][col] = max_lenght;
    return max_lenght;
}

void longest_run(vector<vector<int>>& matrix, string name, int row, int col){
    int longest_path=0;
    vector<vector<int>> longest_run(row, vector<int>(col, -1));
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            longest_path = max(longest_path, backtrack(matrix, i, j, longest_run));
        }
    }
    cout<<name<<": "<<longest_path<<endl;
}

int main(){
    vector<vector<int>> Feldberg = {{56,14,51,58,88},
                                    {26,94,24,39,41},
                                    {24,16,8,51,51},
                                    {76,72,77,43,10},
                                    {38,50,59,84,81},
                                    {5,23,37,71,77},
                                    {96,10,93,53,82},
                                    {94,15,96,69,9},
                                    {74,0,62,38,96},
                                    {37,54,55,82,38}};
    vector<vector<int>> Spiral = {  {1,2,3,4,5},
                                    {16,17,18,19,6},
                                    {15,24,25,20,7},
                                    {14,23,22,21,8},
                                    {13,12,11,10,9}};
    longest_run(Feldberg, "Feldberg", 10, 5);
    longest_run(Spiral, "Spiral", 5, 5);
}