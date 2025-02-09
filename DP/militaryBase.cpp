//Scritto del 21 dicembre 2022
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int lis(vector<int>& arr, int prev_index, int curr_index, vector<vector<int>> &memo) {
    if (curr_index == arr.size()) {
        return 0;
    }

    if (memo[prev_index + 1][curr_index] != -1) {
        return memo[prev_index + 1][curr_index];
    }

    int include = 0;
    if (prev_index == -1 || arr[curr_index] > arr[prev_index]) {
        include = 1 + lis(arr, curr_index, curr_index + 1, memo);
    }

    int exclude = lis(arr, prev_index, curr_index + 1, memo);

    memo[prev_index + 1][curr_index] = max(include, exclude);
    return memo[prev_index + 1][curr_index];
}

int maxNonCrossingChannels(vector<int>& X, vector<int>& Y) {
    int n = X.size();
    vector<pair<int, int>> pairs;

    for (int i = 0; i < n; ++i) {
        pairs.emplace_back(X[i], Y[i]);
    }

    // Sort pairs by X, then by Y
    sort(pairs.begin(), pairs.end());

    vector<int> sorted_Y;
    for (const auto& p : pairs) {
        sorted_Y.push_back(p.second);
    }

    vector<vector<int>> memo (n, vector<int> (n, -1));
    return lis(sorted_Y, -1, 0, memo);
}

int main() {
    vector<int> X = {8,5,3,2};
    vector<int> Y = {3,4,7,6};
    cout<<maxNonCrossingChannels(X, Y)<<endl;

    vector<int> X1 = {2,5,3,9,12,4};
    vector<int> Y1 = {1,7,2,4,3,10};
    cout<<maxNonCrossingChannels(X1, Y1)<<endl;
}