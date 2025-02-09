//Complessità: O(n^3) siccome i e j vanno da 0 a circa n (dimensione del vettore numbers) tuttavia il ciclo for esplora tutte le k posizioni degli operatori e quindi
//fornisce un ulteriore O(n) per una complessità complessiva di O(n^3)
#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

bool isOperator(char op){
    if(op == '+' || op == '*'){
        return true;
    }
    else{
        return false;
    }
}

int maxValue(int i, int j, vector<int> &numbers, vector<char> &operators, vector<vector<int>> &maxMemo){
    if(i == j){
        return numbers[i];
    }

    if(maxMemo[i][j] != -1){
        return maxMemo[i][j];
    }

    int maxSoFar = INT_MIN;

    for(int k = i; k < j; k++){

        int left = maxValue(i, k, numbers, operators, maxMemo);
        int right = maxValue(k+1, j, numbers, operators, maxMemo);

        if(operators[k] == '+'){
            maxSoFar = max(maxSoFar, left + right);
        }
        else if(operators[k] == '*'){
            maxSoFar = max(maxSoFar, left * right);
        }
    }

    maxMemo[i][j] = maxSoFar;

    return maxMemo[i][j];

}

int minValue(int i, int j, vector<int> &numbers, vector<char> &operators, vector<vector<int>> &minMemo){
    if(i == j){
        return numbers[i];
    }

    if(minMemo[i][j] != -1){
        return minMemo[i][j];
    }

    int minSoFar = INT_MAX;

    for(int k = i; k < j; k++){

        int left = minValue(i, k, numbers, operators, minMemo);
        int right = minValue(k+1, j, numbers, operators, minMemo);

        if(operators[k] == '+'){
            minSoFar = min(minSoFar, left + right);
        }
        else if(operators[k] == '*'){
            minSoFar = min(minSoFar, left * right);
        }
    }

    minMemo[i][j] = minSoFar;

    return minMemo[i][j];

}

void maxMinHelper(string expression){
    vector<char> operators;
    vector<int> numbers;
    string tmp = "";

    for(int i = 0; i < expression.size(); i++){
        if(isOperator(expression[i])){
            operators.push_back(expression[i]);
            numbers.push_back(atoi(tmp.c_str()));
            tmp = "";
        }
        else{
            tmp.push_back(expression[i]);
        }
    }
    numbers.push_back(atoi(tmp.c_str()));

    vector<vector<int>> maxMemo (numbers.size(), vector<int> (numbers.size(), -1));
    vector<vector<int>> minMemo (numbers.size(), vector<int> (numbers.size(), -1));

    int MAX = maxValue(0, numbers.size()-1, numbers, operators, maxMemo);
    int MIN = minValue(0, numbers.size()-1, numbers, operators, minMemo);

    cout<<MAX<<" "<<MIN<<endl;
}

int main(){
    string expression1 = "2+4*2*3+7";
    string expression2 = "3*14+19+3*10";
    maxMinHelper(expression1);
    maxMinHelper(expression2);
}