#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int somma_minima(vector<int>& civici){
    int dist = 0;
    int min = 0;
    for(int i = 0; i<civici.size(); i++){
        min=dist;
        dist = 0;
        for(int j = 0; j<civici.size(); j++){
            dist += abs(civici[i] - civici[j]);
        }
        if(dist<min){
            min = dist;
        }
    }
    return min;
}

int main(){
    vector<int> civici = {2,2,4,5,7,10,54,112,238,256};
    int min_dist = somma_minima(civici);
    cout<<min_dist<<endl;
}