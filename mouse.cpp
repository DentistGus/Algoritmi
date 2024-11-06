#include <iostream>
using namespace std;

bool found_solution = false;  // Variabile globale per indicare che una soluzione è stata trovata

bool is_a_solution(int mouse_row, int mouse_col) {
    return (mouse_row == 3 && mouse_col == 3);
}

void process_solution(int output[][4]) {
    cout << "Mouse path:" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << output[i][j];
        }
        cout << endl;
    }
    cout << "------------" << endl;
}

bool is_safe(int maze[][4], int mouse_row, int mouse_col) {
    return (mouse_row >= 0 && mouse_row < 4 && mouse_col >= 0 && mouse_col < 4 && maze[mouse_row][mouse_col] == 1);
}

void backtrack(int output[][4], int maze[][4], int mouse_row, int mouse_col) {
    if (found_solution) return;  // Interrompe l'esecuzione se una soluzione è già stata trovata
    if (is_a_solution(mouse_row, mouse_col)) {
        process_solution(output);
        found_solution = true;  // Segnala che la soluzione è stata trovata
        return;
    }

    // Array per le direzioni: destra, giù, sinistra, su
    int directions[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

    for (int i = 0; i < 4; i++) {
        int new_row = mouse_row + directions[i][0];
        int new_col = mouse_col + directions[i][1];

        // Se la mossa è sicura e la cella non è già stata visitata
        if (is_safe(maze, new_row, new_col) && output[new_row][new_col] == 0) {
            output[new_row][new_col] = 1;  // Segna la cella come parte del percorso
            backtrack(output, maze, new_row, new_col);  // Prova a muoverti ricorsivamente

            // Backtracking: resetta la cella se non porta alla soluzione
            if (!found_solution) {
                output[new_row][new_col] = 0;
            }
        }
    }
}

int main() {
    cout << "Structure of the maze:" << endl;

    int maze[4][4] = {
        {1, 1, 1, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };
    int output[4][4] = {
        {1, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << maze[i][j];
        }
        cout << endl;
    }
    cout << "------------" << endl;

    backtrack(output, maze, 0, 0);

    if (!found_solution) {
        cout << "No solution found." << endl;
    }

    return 0;
}
