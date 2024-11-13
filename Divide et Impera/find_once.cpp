/*Given a sorted array arr[] of size N. Find the element that appears only once in the array. All other elements appear exactly twice.*/

#include <iostream>
#include <vector>

using namespace std;


int findOnce(vector<int>& input, int begin, int end){
    int index = (begin+end)/2;
    /*Se l'index e'dispari allora mi aspetto che il valore in index sia uguale al precedente nel caso in cui il numero solitario stia sulla parte dx del vettore*/
    if(index%2 != 0){
        if(input[index]==input[index-1]){
            return findOnce(input, index, end);
        }
        /*Se invece trovo corrispondenza con il successivo allora il numero solitario si trova sulla sx del vettore*/
        else if(input[index]==input[index+1]){
            return findOnce(input, begin, index);
        }
        /*Se non ho trovato alcuna corrispondenza con i valori adiacenti allora l'ho trovato...*/
        else{
            return input[index];
        }
    }
    /*Quando l'index e' pari la logica si inverte. Se trovo corrisponendenza con il successivo allora il numero solitario si trova sulla dx del vettore*/
    else{
        if(input[index]==input[index+1]){
            return findOnce(input, index, end);
        }
        /*Se invece trovo corrispondenza con il precedente allora il numero solitario si trova sulla sx del vettore*/
        else if(input[index]==input[index-1]){
            return findOnce(input, begin, index);
        }
        /*Se non ho trovato alcuna corrispondenza con i valori adiacenti allora l'ho trovato...*/
        else{
            return input[index];
        }
    }
}

int main(){
    vector<int> input = {1, 1, 2, 2, 3, 3, 4, 50, 50, 65, 65};
    cout<<findOnce(input, 0, input.size()-1)<<endl;
}