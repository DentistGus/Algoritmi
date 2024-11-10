/*
Caso Migliore: se num non è presente nel vettore, l'algoritmo si ferma dopo O(log n) operazioni, poiché si esegue solo la ricerca binaria e non si procede al conteggio.
Caso Medio: se num appare solo un numero limitato di volte (come un piccolo sottoinsieme di elementi contigui), la ricerca binaria si esegue in O(log n) e il conteggio ha complessità 
O(k), dove k è il numero di occorrenze di num. In questo caso, la complessità totale sarebbe O(logn + k).
Caso Peggiore: se tutti gli elementi nel vettore sono uguali a num, dopo la ricerca binaria l'algoritmo dovrà eseguire O(n) operazioni per contare tutte le occorrenze. In questo caso, 
la complessità complessiva diventa O(n).
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int occurrences(vector<int>& vec, int num, int begin, int end){
    int index = floor((begin + end)/2);
    if(index+1 == end && vec[index] != num && vec[index+1] != num && vec[index-1] != num){
        return 0;
    }
    else if(vec[index] > num){
        //Devo cercare a sx del vettore
        return occurrences(vec, num, begin, index);
    }
    else if(vec[index] < num){
        //Devo cercare a dx del vettore
        if(index+1 == end && vec[index+1] == num){
            return 1;
        }
        return occurrences(vec, num, index, end);
    }
    else if(vec[index] == num){
        int prev = index-1;
        int next = index+1;
        int cnt = 1;
        while(vec[prev] == num){
            cnt++;
            prev--;
        }
        while(vec[next] == num){
            cnt++;
            next++;
        }
        return cnt;
    }
    return 0;
}

int main(){
    vector<int> vec = {1,1,2,2,2,2,3,3,4};
    sort(vec.begin(), vec.end());
    int cnt0 = occurrences(vec, 0, 0, vec.size()-1);
    int cnt1 = occurrences(vec, 1, 0, vec.size()-1);
    int cnt2 = occurrences(vec, 2, 0, vec.size()-1);
    int cnt3 = occurrences(vec, 3, 0, vec.size()-1);
    int cnt4 = occurrences(vec, 4, 0, vec.size()-1);
    cout<<cnt0<<endl;
    cout<<cnt1<<endl;
    cout<<cnt2<<endl;
    cout<<cnt3<<endl;
    cout<<cnt4<<endl;
}