//ERRATO
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> toBeProcessed = {-1,-1};
vector<int> finish = {0,0};

vector<int> jobShop(vector<int> &id, vector<int> &deadline, vector<int> &profit, int currentId, int time, int reward, vector<vector<int>> &memo, vector<pair<int, int>> &ans){
    if(currentId == id.size() || time == id.size()){
        return finish;
    }

    if(memo[currentId] != toBeProcessed){
        return memo[currentId];
    }

    vector<pair<int, int>> take;
    vector<pair<int, int>> no_take;

    for(const auto & job : ans){
        if(job.first > time){
            take.push_back({1 + jobShop(id, deadline, profit, currentId+1, time+1, reward, memo, ans)[currentId], job.second});
        }
        no_take.push_back({jobShop(id, deadline, profit, currentId+1, time, reward, memo,ans)[currentId], 0});
    }

    /*if(deadline[currentId] > time){
        take = 1 + jobShop(id, deadline, profit, currentId+1, time+1, reward, memo, ans);
    }

    no_take = jobShop(id, deadline, profit, currentId+1, time, reward, memo,ans);*/

    for(const auto & p : take){
        memo[currentId] = {p.first, p.second};
    }

    return memo[currentId];

}

vector<int> jobShopHelper(vector<int> &id, vector<int> &deadline, vector<int> &profit){
    int currentId = 0;
    int time = 0;
    int reward = 0;
    vector<pair<int, int>> ans;

    for(int i = 0; i < id.size(); i++){
        ans.push_back({deadline[i], profit[i]});
    }

    sort(ans.begin(), ans.end());

    /*for(const auto &p : ans){
        cout<<"("<<p.first<<", "<<p.second<<")";
    }
    cout<<endl;*/

    vector<vector<int>> memo (id.size(), vector<int> (id.size(), -1));
    return jobShop(id, deadline, profit, currentId, time, reward, memo, ans); 
}

int main(){
    vector<int> id1 = {1,2,3,4};
    vector<int> deadline1 = {4,1,1,1};
    vector<int> profit1 = {20,1,40,30};
    for(int i = 0; i<jobShopHelper(id1, deadline1, profit1).size(); i++){
        cout<<jobShopHelper(id1, deadline1, profit1)[i]<<endl;
    }

    /*vector<int> id2 = {1,2,3,4,5};
    vector<int> deadline2 = {2,1,2,1,1};
    vector<int> profit2 = {100,19,27,25,15};
    cout<<jobShopHelper(id2, deadline2, profit2)<<endl;

    vector<int> id3 = {1,2,3,4};
    vector<int> deadline3 = {3,1,2,2};
    vector<int> profit3 = {50,10,20,30};*
    cout<<jobShopHelper(id3, deadline3, profit3)<<endl;*/
}