//scritto del 16/03/2022
#include <iostream>
#include <vector>
#include <climits>
#include <string>

using namespace std;

bool isOperator(char op){
    return (op == '+' || op == '*');
}

int maxValue(vector<int> &num, vector<char> &operators, int index, int end, vector<vector<int>> &maxMemo){
    if(index == end){
        return num[index];
    }

    if(maxMemo[index][end] != -1){
        return maxMemo[index][end];
    }

    int maxSoFar = INT_MIN;

    for(int k = index; k < end; k++){

        int leftMax = maxValue(num, operators, index, k, maxMemo);
        int rightMax = maxValue(num, operators, k+1, end, maxMemo);

        if(operators[k] == '+'){
            maxSoFar = max(maxSoFar, leftMax + rightMax);
        }
        else if(operators[k] == '*'){
            maxSoFar = max(maxSoFar, leftMax * rightMax);
        }
    }

    maxMemo[index][end] = maxSoFar;

    return maxMemo[index][end];

}

int minValue(vector<int> &num, vector<char> &operators, int index, int end, vector<vector<int>> &minMemo){
    if(index == end){
        return num[index];
    }

    if(minMemo[index][end] != -1){
        return minMemo[index][end];
    }

    int minSoFar = INT_MAX;

    for(int k = index; k < end; k++){

        int leftMin = minValue(num, operators, index, k, minMemo);
        int rightMin = minValue(num, operators, k+1, end, minMemo);

        if(operators[k] == '+'){
            minSoFar = min(minSoFar, leftMin + rightMin);
        }
        else if(operators[k] == '*'){
            minSoFar = min(minSoFar, leftMin * rightMin);
        }
    }

    minMemo[index][end] = minSoFar;

    return minMemo[index][end];

}

void minMaxValues(string exp){
    string tmp = "";
    vector<char> operators;
    vector<int> num;

    for(int i = 0; i < exp.length(); i++){
        if(isOperator(exp[i])){
            operators.push_back(exp[i]);
            num.push_back(atoi(tmp.c_str()));
            tmp = "";
        }
        else{
            tmp += exp[i];
        }
    }
    num.push_back(atoi(tmp.c_str()));

    int index = 0;
    int end = num.size();
    vector<vector<int>> maxMemo (end, vector<int> (end, -1));
    vector<vector<int>> minMemo (end, vector<int> (end, -1));

    int MAX = maxValue(num, operators, index, end-1, maxMemo);
    int MIN = minValue(num, operators, index, end-1, minMemo);

    cout<<MAX<<" "<<MIN<<endl;
    
}

int main(){
    string exp1 = "2+4*2*3+7";
    minMaxValues(exp1);

    string exp2 = "3*14+19+3*10";
    minMaxValues(exp2);
}