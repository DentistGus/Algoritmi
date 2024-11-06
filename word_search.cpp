#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_safe(vector<vector<char>>& board, int row, int col, vector<vector<bool>>& path, char target){
    return row >= 0 && row < board.size() &&
           col >= 0 && col < board[0].size() &&
           board[row][col] == target && !path[row][col];
}

bool backtrack(vector<vector<char>>& board, string &word, int index, int row, int col, vector<vector<bool>>& path) {
    if (index == word.size()) return true;

    if (!is_safe(board, row, col, path, word[index])) return false;

    // Mark the cell as part of the path
    path[row][col] = true;

    // Explore all 4 possible directions
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for (int i = 0; i < 4; i++) {
        int new_row = row + directions[i][0];
        int new_col = col + directions[i][1];

        if (backtrack(board, word, index + 1, new_row, new_col, path)) return true;
    }

    // Backtrack: unmark the cell
    path[row][col] = false;
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    int rows = board.size();
    int cols = board[0].size();
    vector<vector<bool>> path(rows, vector<bool>(cols, false));

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (backtrack(board, word, 0, row, col, path)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };

    string word = "ABCCED";

    if (exist(board, word)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
