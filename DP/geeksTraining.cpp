#include <iostream>
#include <vector>

using namespace std;

int geekTrainingDP(vector<vector<int>> &activity, int prev, int curr, vector<vector<int>> &memo){
    if(curr == activity.size()) return 0;

    if(memo[curr][prev+1] != -1) return memo[curr][prev+1];

    int maxMerit = INT_MIN;

    for(int i = 0; i < activity.size(); i++){
        if(i != prev){
            int val = activity[curr][i] + geekTrainingDP(activity, i, curr+1, memo);

            maxMerit = max(maxMerit, val);
        }
    }

    return memo[curr][prev+1]=maxMerit;

}

int geekTraining(vector<vector<int>> &activity){
    int days = activity.size();
    vector<vector<int>> memo (days, vector<int> (days+1, -1));
    int prev = -1;
    int curr = 0;
    return geekTrainingDP(activity, prev, curr, memo);
}

int main(){
    vector<vector<int>> activity = {{1,2,5},{3,1,1},{3,3,3}};
    cout<<geekTraining(activity)<<endl;
}