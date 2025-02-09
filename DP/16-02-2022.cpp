//Scritto del 16/02/2022
//Complessità: O(n x budget x m), il contributo di m viene dato dal ciclo for 
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int buyProduct(int budget, int index, int classes, vector<vector<int>> &products, vector<vector<int>> &memo){
    if(budget < 0){
        return -1;
    }

    if(index == classes){
        return 0;
    }

    if(memo[index][budget] != -1){
        return memo[index][budget];
    }

    int maxSoFar = INT_MIN;

    for(int k = 0; k < products[index].size(); k++){
        if(budget >= products[index][k]){
            maxSoFar = max(maxSoFar, buyProduct(budget-products[index][k], index+1, classes, products, memo) + products[index][k]);    
        }    
    }
    memo[index][budget] = maxSoFar;

    return memo[index][budget];

}

void buyProductHelper(int budget, vector<vector<int>> &products){
    int index = 0;
    int classes = products.size();
    vector<vector<int>> memo (classes, vector<int> (budget+1, -1));
    int ans = buyProduct(budget, index, classes, products, memo);
    if(ans < 0){
        cout<<"denaro insufficiente"<<endl;
    }
    else{
        cout<<ans<<endl;
    }
}

int main(){
    int budget1 = 100;
    vector<vector<int>> products1 = {{8,6,4},{5,10},{1,3,3,7},{50,14,23,8}};
    buyProductHelper(budget1, products1);

    int budget2 = 20;
    vector<vector<int>> products2 = {{4,6,8},{5,10},{1,3,5,5}};
    buyProductHelper(budget2, products2);

    int budget3 = 5;
    vector<vector<int>> products3 = {{6,4,8},{10,6},{7,3,1,7}};
    buyProductHelper(budget3, products3);
}