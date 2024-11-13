/*Given a sorted and rotated array A of N distinct elements which are rotated at some point, and given an element K. The task is to find the index of the given element K in array A.*/

#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& vec, int k, int begin, int end){
    int first_elem = vec[0];
    int last_elem = vec[vec.size()-1];
    int index = (begin+end)/2;
    if(k == first_elem){
        return 0;
    }
    else if (k == last_elem){
        return vec.size()-1;
    }
    if(begin != (end-1)){
        if(k > first_elem && vec[index] < k && vec[index] > first_elem){
            //cerca a  dx
            return search(vec, k, index, end);
        }
        else if(k > first_elem && vec[index] < k && vec[index] < first_elem){
            //cerca a  sx
            return search(vec, k, begin, index);
        }
        else if(k > first_elem && vec[index] > k){
            //cerca a sx
            return search(vec, k, begin, index);
        }
        else if(k < first_elem && vec[index] < k){
            //cerca a dx
            return search(vec, k, index, end);
        }
        else if(k < first_elem && vec[index] > k && vec[index] > first_elem){
            //cerca a dx
            return search(vec, k, index, end);
        }
        else if(k < first_elem && vec[index] > k && vec[index] < first_elem){
            //cerca a sx
            return search(vec, k, begin, index);
        }
        else if (vec[index] == k){
            return index;
        }
    }
    return -1;
}

int main(){
    vector<int> input = {5,7,8,9,10,1,3};
    for(int i = 0; i<11; i++){
        cout<<"Searching the index for "<<i<<" element: "<<search(input, i, 0, input.size()-1)<<endl;
    }
}