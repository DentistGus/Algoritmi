//Prova del 16/02/2022
#include <iostream>
#include <vector>

using namespace std;

int buyProduct(vector<vector<int>> &classiProdotti, int budget, int i, int numProdotti, vector<vector<int>> &memo){
    if(budget < 0){
        return -1e9;
    }

    if(i == numProdotti){
        return 0;
    }

    if(memo[i][budget] != -1){
        return memo[i][budget];
    }

    int max_spent = -1e9;

    for(int k = 0; k < classiProdotti[i].size(); k++){
        if(budget >= classiProdotti[i][k]){
           max_spent = max(max_spent, classiProdotti[i][k] + buyProduct(classiProdotti, budget-classiProdotti[i][k], i+1, numProdotti, memo));
        }
    }

    memo[i][budget] = max_spent;

    return memo[i][budget];

}

void buyProductHelper(vector<vector<int>> &classiProdotti, int budget, int numProdotti){
    int i = 0;
    int n = numProdotti;
    vector<vector<int>> memo (numProdotti, vector<int> (budget+1, -1));
    int result = buyProduct(classiProdotti, budget, i, numProdotti, memo);

    if(result < 0){
        cout<<"denaro insufficiente"<<endl;
    }
    else{
        cout<<result<<endl;
    }

}

int main(){
    int budget = 100;
    int numProdotti = 4;
    vector<vector<int>> classiProdotti = {{8,6,4},{5,10},{1,3,3,7},{50,14,23,8}}; 
    buyProductHelper(classiProdotti, budget, numProdotti);
    
    int budget2 = 20;
    int numProdotti2 = 3;
    vector<vector<int>> products2 = {{4,6,8},{5,10},{1,3,5,5}};
    buyProductHelper(products2, budget2, numProdotti2);

    int budget3 = 5;
    int numProdotti3 = 3;
    vector<vector<int>> products3 = {{6,4,8},{10,6},{7,3,1,7}};
    buyProductHelper(products3, budget3, numProdotti3);
}