//Scritto del 17/01/2022 
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>

using namespace std;

map<pair<int, int>, int> memo_time;
map<pair<int, int>, int> memo_trips;

// Funzione ricorsiva per calcolare il minimo tempo
int min_time(int index, int time, const vector<int>& arrival, int n, int t) {
    if (index >= arrival.size()) {
        return time;
    }
    
    pair<int, int> state = {index, time};
    if (memo_time.find(state) != memo_time.end()) {
        return memo_time[state];
    }
    
    int next_time = max(time, arrival[index]);
    int last_car_time = 0;
    
    for (int i = 0; i < n && index + i < arrival.size(); i++) {
        last_car_time = max(next_time, arrival[index + i]);
    }
    
    int result = min_time(index + n, last_car_time + t, arrival, n, t);
    return memo_time[state] = result;
}

// Funzione ricorsiva per calcolare il numero minimo di viaggi
int min_trips(int index, int time, const vector<int>& arrival, int n, int t) {
    if (index >= arrival.size()) {
        return 0;
    }
    
    pair<int, int> state = {index, time};
    if (memo_trips.find(state) != memo_trips.end()) {
        return memo_trips[state];
    }
    
    int next_time = max(time, arrival[index]);
    int last_car_time = 0;
    
    for (int i = 0; i < n && index + i < arrival.size(); i++) {
        last_car_time = max(next_time, arrival[index + i]);
    }
    
    int result = min_trips(index + n, last_car_time + t, arrival, n, t) + 1;
    return memo_trips[state] = result;
}

void riverFerries(vector<int> &info, vector<int> &arrival){
    memo_time.clear(); // Resettiamo la memoization per ogni test case
    memo_trips.clear();
    
    int result_time = min_time(0, 0, arrival, info[0], info[1]);
    int result_trips = min_trips(0, 0, arrival, info[0], info[1]);
        
    cout << result_time << " " << result_trips << endl;
}

int main(){
    vector<int> info = {2,10,10};
    vector<int> arrival = {0,10,20,30,40,50,60,70,80,90};
    riverFerries(info, arrival);

    vector<int> info1 = {2,10,3};
    vector<int> arrival1 = {10,30,40};
    riverFerries(info1, arrival1);
}