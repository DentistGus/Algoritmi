#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minCoinsForAtLeastAmount(int amount, vector<int>& coins) {
    // Stima di un limite superiore ragionevole (ad esempio, 2 volte l'importo)
    int upperLimit = 2 * amount;
    vector<int> dp(upperLimit + 1, INT_MAX);
    dp[0] = 0;  // Nessuna moneta necessaria per l'importo 0

    for (int i = 1; i <= upperLimit; i++) {
        for (int coin : coins) {
            if (coin <= i && dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    // Cerca il primo importo fattibile almeno uguale all'importo desiderato
    for (int i = amount; i <= upperLimit; i++) {
        if (dp[i] != INT_MAX) {
            return dp[i];
        }
    }

    return -1;  // Se non si trova nessun importo fattibile
}

int main() {
    vector<int> coins1 = {1, 5};
    int amount1 = 10;
    vector<int> coins2 = {1, 3, 4, 5};
    int amount2 = 7;

    cout << minCoinsForAtLeastAmount(amount1, coins1) << endl;  // Output: 2
    cout << minCoinsForAtLeastAmount(amount2, coins2) << endl;  // Output: 2

    // Additional test cases
    vector<int> coins3 = {2, 3, 5};
    int amount3 = 11;

    cout << minCoinsForAtLeastAmount(amount3, coins3) << endl;  // Output: 3

    vector<int> coins4 = {3, 5};
    int amount4 = 11;

    cout << minCoinsForAtLeastAmount(amount4, coins4) << endl;  // Output: 3

    return 0;
}
