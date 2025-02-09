//A differenza del vero scritto del 16/02/2022 questa soluzione trova la sottomatrice quadrata di dimensione massima; la traccia richiedeva di trovare la matrice
//di dimensione massima in assoluto che quindi può essere anche rettangolare.
//Complessità: O(MxN)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Funzione ricorsiva con memoization per calcolare la sottomatrice massima
int maxFreeSubmatrix(vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &memo) {
    if (i < 0 || j < 0) return 0; // Se siamo fuori dalla matrice, restituiamo 0
    if (matrix[i][j] == 1) return 0; // Se la cella è occupata, non fa parte della sottomatrice
    
    if (memo[i][j] != -1) return memo[i][j]; // Se il valore è già stato calcolato, restituiamolo
    
    // Calcola la dimensione massima della sottomatrice considerando le sottomatrici adiacenti
    memo[i][j] = 1 + min({
        maxFreeSubmatrix(matrix, i - 1, j, memo),
        maxFreeSubmatrix(matrix, i, j - 1, memo),
        maxFreeSubmatrix(matrix, i - 1, j - 1, memo)
    });
    
    return memo[i][j];
}

// Funzione principale per trovare la sottomatrice massima
int findLargestZeroSubmatrix(vector<vector<int>> &matrix, int M, int N) {
    vector<vector<int>> memo (M, vector<int>(N, -1)); // Inizializza la tabella di memoization
    int maxZeros = 0;
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] == 0) {
                maxZeros = max(maxZeros, maxFreeSubmatrix(matrix, i, j, memo));
            }
        }
    }
    
    return maxZeros * maxZeros; // Numero totale di '0' nella sottomatrice più grande
}

int main() {
    vector<vector<int>> matrix = {{0,1,1,0,1,1,0},{0,0,0,0,0,1,0},{1,0,0,0,0,0,1},{0,1,0,0,0,0,1},{1,1,0,0,0,1,0},{1,1,0,1,1,0,0}};
    int M = matrix.size();
    int N = matrix[0].size();    
    cout << findLargestZeroSubmatrix(matrix, M, N) << endl;
}
