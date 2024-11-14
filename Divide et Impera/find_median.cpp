/*Questo esercizio è alla base dei problemi visti sulla famiglia di Vito o del signor Rossi*/
/*Given an array arr[] of integers, calculate the median.
NOTE: Return the floor value of the median*/

#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& array, int begin, int end){
    int pivot = array[end];
    int i = begin-1;
    int tmp;
    for(int j = begin; j < end; j++){
        if(array[j] <= pivot){
            i = i+1;
            tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
        }
    }
    tmp = array[i+1];
    array[i+1] = array[end];
    array[end] = tmp;
    return i+1;
}

void quicksort(vector<int>& array, int begin, int end){
    if(begin<end){
        int index = partition(array, begin, end);
        quicksort(array, begin, index-1);
        quicksort(array, index+1, end);
    }
}

int find_median(vector<int>& array){
    int index=(array.size()-1)/2;
    if(array.size()%2 == 1){
        return array[index];
    }
    else{
        return (array[index] + array[index+1])/2;
    }
}

int main(){
    vector<int> odd_array = {90, 100, 78, 89, 67};
    vector<int> even_array = {56, 67, 30, 79};
    quicksort(odd_array, 0, odd_array.size()-1);
    quicksort(even_array, 0, even_array.size()-1);
    cout<<find_median(odd_array)<<endl;
    cout<<find_median(even_array)<<endl;
}