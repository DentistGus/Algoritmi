#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void bellman_ford(int V, vector<vector<int>> &edges){
    int dp[V];
    bool valid_graph = true;

    for(int i = 0; i < V; i++){
        if(i==0) dp[i] = 0;
        else dp[i] = 100000000;
    }

    int relax = 0;

    for(int i = 0; i < V; i++){
        if(dp[edges[i][0]] + edges[i][2] < dp[edges[i][1]]){
            dp[edges[i][1]] = dp[edges[i][0]] + edges[i][2];
            i = 0;
            relax++;
        }
        if(relax > V){
            cout<<"Presenza di cicli con peso totale negativo..."<<endl;
            valid_graph = false;
            break;
        }
    }

    if(valid_graph){
        cout<<"[";
        for(int i = 0; i < V; i++){
            cout<<dp[i]<<", ";
        }
        cout<<"]"<<endl;
    }

}

int main(){
    int V1 = 5;
    vector<vector<int>> edges1 = {{1,3,2},{4,3,-1},{2,4,1},{1,2,1},{0,1,5}};
    bellman_ford(V1, edges1);

    int V2 = 4;
    vector<vector<int>> edges2 = {{0,1,4},{1,2,-6},{2,3,5},{3,1,-2}};
    bellman_ford(V2, edges2);

}