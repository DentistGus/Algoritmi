#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool is_solution(int result_size, int n){
    if(result_size == pow(2, n)) return true;
    else return false;
}

void process_solution(vector<int>& result){
    cout<<"[";
    for(int i = 0; i<result.size(); i++){
        if(i==result.size()-1){
            cout<<result[i];
        }
        else cout<<result[i]<<", ";
    }
    cout<<"]";
    return;
}

bool diffByBit(int num1, int num2){
    int xorResult = num1 ^ num2;
    return xorResult != 0 && (xorResult & (xorResult-1)) == 0;
}

bool is_safe(vector<int>& result, int num){
    for(int i = 0; i<result.size(); i++){
        if(result[i]==num){
            return false;
        }
    }
    return true;
}

void backtrack(vector<int>& result, vector<int>& dec, int n, int index){
    if(is_solution(result.size(), n)){
        process_solution(result);
        return;
    }
    else{
        for(int i = index; i<pow(2, n); i++){
            if(result.size()==0){
                result.push_back(dec[i]);
                backtrack(result, dec, n, index+1);
                //result.pop_back();
            }
            else{
                //cout<<"Sto confrontando "<<dec[i]<<" con "<<result.back()<<endl;
                if((diffByBit(dec[i], result.back()) && is_safe(result, dec[i]))){
                    //cout<<"check ok"<<endl;
                    result.push_back(dec[i]);
                    backtrack(result, dec, n, index+1);
                    //result.pop_back();
                }
            }
        }
    }
}

vector<int> grayCode(int n){
    vector<int> result;
    vector<int> dec;
    int index = 0;
    for(int i = 0; i<pow(2, n); i++){
        dec.push_back(i);
    }
    backtrack(result, dec, n, index);
    return result;
}

int main(){
    int n = 3;
    vector<int> output = grayCode(n);
}
