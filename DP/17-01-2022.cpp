//Complessità: O(m x n) cioè dipende dalle m auto da trasportare e dalla capacità del traghetto, ossia n.
#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<pair<int,int>, int> memo_time;
map<pair<int,int>, int> memo_trip; 

int minTime(int index, int time, vector<int> &arrival, int n, int t){
    if(index >= arrival.size()){
        return time;
    }

    pair<int,int> state = {index, time};

    if(memo_time.find(state) != memo_time.end()){
        return memo_time[state];
    }

    int next_time = max(time, arrival[index]);
    int last_car_time = 0;

    for(int i = 0; i < n && index + i < arrival.size(); i++){
        last_car_time = max(next_time, arrival[index+i]);
    }

    int result = minTime(index +  n, last_car_time + t, arrival, n, t);
    return memo_time[state] = result;

}

int minTrip(int index, int time, vector<int> &arrival, int n, int t){
    if(index >= arrival.size()){
        return 0;
    }

    pair<int,int> state = {index, time};

    if(memo_trip.find(state) != memo_trip.end()){
        return memo_trip[state];
    }

    int next_time = max(time, arrival[index]);
    int last_car_time = 0;

    for(int i = 0; i < n && index + i < arrival.size(); i++){
        last_car_time = max(next_time, arrival[index+i]);
    }

    int result = minTrip(index +  n, last_car_time + t, arrival, n, t) + 1;
    return memo_trip[state] = result;
    
}

void riverFerries(vector<int> &info, vector<int> &arrival){
    memo_time.clear();
    memo_trip.clear();

    int min_time = minTime(0, 0, arrival, info[0], info[1]);
    int min_trip = minTrip(0, 0, arrival, info[0], info[1]);

    cout<<min_time<<" "<<min_trip<<endl;
}

int main(){
    vector<int> info = {2,10,10};
    vector<int> arrival = {0,10,20,30,40,50,60,70,80,90};
    riverFerries(info, arrival);
}