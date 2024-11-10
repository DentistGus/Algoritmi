/*Sia data una tripla di interi S, N e P. S indica una somma. P indica un numero primo. Si trovino tutti
gli N numeri primi strettamente maggiori di P tali che la loro somma è uguale ad S. Possono esistere
più sequenze che soddisfano tale condizione.*/

#include <iostream>
#include <vector>

using namespace std;

bool is_safe(vector<int>& result, int sum){
    int tmp = 0;
    for(int i = 0; i<result.size(); i++){
        tmp += result[i];
    }
    if(tmp == sum) return true;
    else return false;
}

bool sort_result(vector<int>& result){
    for(int i = 0; i<result.size()-1; i++){
        if(result[i]>result[i+1]) return false;
    }
    return true;
}

bool is_solution(vector<int>& result, int sum, int n){
    if(result.size() == n && is_safe(result,sum) && sort_result(result)) return true;
    else return false;
}

void process_solution(vector<int>& result){
    for(int i = 0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
}

bool check_prime(int prime_num){
    if (prime_num <= 1) { 
        return false;
    }
    for(int i = 2; i<prime_num; i++){
        if(prime_num%i == 0){
            return false;
        }
    }
    return true;
}

vector<int> generates_prime_numbers(int sum, int p){
    vector<int> primes;
    for (int num = p + 1; num <= sum; num++) {
        if(check_prime(num)) {
            primes.push_back(num);
        }
    }
    return primes;
}    

void backtrack(vector<int>& result, int sum, int n, int p, vector<int>& primes){
    if(is_solution(result, sum, n)){
        process_solution(result);
    }
    for(int i = 0; i<primes.size(); i++){
        if(result.size()<n){
            result.push_back(primes[i]);
            backtrack(result, sum, n, p, primes);
            result.pop_back();
        }
    }
}

vector<int> find_n_prime_numbers(vector<int>& input){
    vector<int> result;
    int sum = input[0];
    int n = input[1];
    int p = input[2];
    vector<int> primes = generates_prime_numbers(sum, p);
    backtrack(result, sum, n, p, primes);
    return result;
}

int main(){
    vector<vector<int>> test_suite;
    vector<int> test1 = {63,3,5};
    vector<int> test2 = {23,3,2};
    vector<int> test3 = {17,1,5};
    test_suite.push_back(test1);
    test_suite.push_back(test2);
    test_suite.push_back(test3);
    for(int i = 0; i<test_suite.size(); i++){
        cout<<"CASO DI TEST "<<i+1<<endl;
        find_n_prime_numbers(test_suite[i]);
    }
}