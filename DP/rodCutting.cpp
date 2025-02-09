#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int cutRod(vector<int> &price, int index, int length, vector<vector<int>> &memo){
    if(index == price.size()-1 || length == 0) return 0;
    if(memo[index][length] != -1) return memo[index][length];

    int take = INT_MIN;
    int no_take = INT_MIN;

    if(index <= length){
        take = price[index] + cutRod(price, index, length-index, memo);
    }

    no_take = cutRod(price, index+1, length, memo);

    memo[index][length] = max(take, no_take);

    return memo[index][length];
}

int cutRodHelper(vector<int> &price){
    if(price.size() == 1) return price[0];

    int index = 1;
    int length = price.size();
    
    price.insert(price.begin(), -1);
    vector<vector<int>> memo (length+1, vector<int> (length+1, -1));
    return cutRod(price, index, length, memo);
}

int main(){
    vector<int> price1 = {1,5,8,9,10,17,17,20};
    cout<<cutRodHelper(price1)<<endl;

    vector<int> price2 = {3,5,8,9,10,17,17,20};
    cout<<cutRodHelper(price2)<<endl;

    vector<int> price3 = {1,10,3,1,3,1,5,9};
    cout<<cutRodHelper(price3)<<endl;

    vector<int> price4 = {2};
    cout<<cutRodHelper(price4)<<endl;
}