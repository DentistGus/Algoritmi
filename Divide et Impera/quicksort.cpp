/*
Il Quicksort risulta avere una complessità temporale pari a:
• Θ(n^2) nel caso peggiore
• Θ(nlogn) nel caso medio
Tuttavia il caso peggiore si verifica solo quando il pivot è in effetti l'elemento più piccolo presente nel vettore, si è dimostrato che nella pratica questo molto spesso non accade.
*/
#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& array, int begin, int end){
    int pivot = array[end];
    int i = begin-1;
    int tmp; //Variabile che mi serve per gli swap
    for(int j = begin; j<end; j++){
        //Nell'if mi focalizzo sull'area dei numeri non ancora analizzati. Se tali numeri sono <= del pivot allora devo incrementare l'area 1 (dei numeri minori del pivot),
        //successivamente mi preparo per lo swap dell'elemento a[i] con a[j] siccome a[i] sta temporanemante puntando ad un elemento che è > del pivot. Dopo lo swap questo elemento
        //verrà correttamente collocato nell'area 2 (dei numeri strettamente maggiori del pivot). Finito questo posso uscire dal ciclo for.
        //N.B.: Non entrare mai nell'if equivale a dire che il vettore è già ordinato in ordine crescente rispetto al pivot, solo il pivot va spostato.
        if(array[j] <= pivot){
            i = i+1;
            tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
        }
    }
    //Infine devo necessariamente scambiare il primo elemento dell'area 2 (dei numeri strettamente maggiori del pivot) con il pivot stesso.
    //Quello che prima era il primo elemento dell'area 2 adesso assumerà il ruolo di pivot nella successiva iterazione.
    tmp = array[i+1];
    array[i+1] = array[end];
    array[end] = tmp;
    return i+1;
}

void quicksort(vector<int>& array, int begin, int end){
    if(begin<end){
        int index = partition(array, begin, end);
        //Ordino il sottoarray di sinistra
        quicksort(array, begin, index-1);
        //Ordino il sottoarray di destra
        quicksort(array, index+1, end);
    }
}

int main(){
    vector<int> array = {2,8,7,1,3,5,6,4};
    quicksort(array, 0, array.size()-1);
    for(int i = 0; i<array.size(); i++){
        cout<<array[i]<<" ";
    }
}