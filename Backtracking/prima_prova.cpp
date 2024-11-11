/*Sia data in input una stringa di caratteri. Si implementi un algoritmo di backtracking per stampare
tutte le possibili stringhe che possono essere create posizionando uno spazio oppure nessuno spazio
tra i caratteri. Ad esempio con “XYZ” posso ottenere: XYZ, XY Z, X YZ, X Y Z.*/
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

bool is_solution(int result_size, int word_size){
    if(result_size == pow(2, word_size-1)) return true;
    else return false;
}

void process_solution(vector<string>& result){
    for(int i = 0; i<result.size(); i++){
        cout<<result[i]<<endl;
    }
    cout<<"*END*"<<endl;
}

void backtrack(vector<string>& result, string word, int index){
    if(is_solution(result.size(), word.size())){
        process_solution(result);
        return;
    }
    if(result.empty()){
        result.push_back(word);
    }
    int size = result.size();
    for(int i = 0; i<size; i++){
            string tmp = result[i];
            tmp.insert(index, 1, ' '); 
            result.push_back(tmp);
    }
    backtrack(result, word, index-1);        
}

vector<string> space_gen(string word){
    vector<string> result={};
    int index=word.size()-1;
    backtrack(result, word, index);
    return result;
}

int main(){
    string test1 = "XYZ";
    string test2 = "ABCDE";
    vector<string> test_suite;
    test_suite.push_back(test1);
    test_suite.push_back(test2);
    for(int i = 0; i<test_suite.size(); i++){
        space_gen(test_suite[i]);
    }
}