#include <iostream>
#include <vector>

using namespace std;

int find_missing_num(vector<int>& succ, int begin, int end){
    int index = (begin + end)/2;
    bool found = false;
    if(succ.size()>=3){
        if((succ[index]-succ[index-1])==(succ[index+1]-succ[index])){
            //vai a dx
            while(index!=end && begin!=index){
                cout<<"sono a dx"<<endl;
                return find_missing_num(succ, index, end);
            }
            //vai a sx
            while(found!=true){
                cout<<"sono a sx"<<endl;
                return find_missing_num(succ, begin-1, end-1);
            }
        }
        else{
            int tmp = min(succ[index]-succ[index-1], succ[index+1]-succ[index]);
            found=true;
            if(succ[index]-succ[index-1]>succ[index+1]-succ[index]){
                return succ[index]-tmp;
            }
            else return succ[index+1]-tmp;
        }
    }
    return 0;
}

int main(){
    vector<int> succ1 = {1,3,5,9};
    vector<int> succ2 = {3, 9, 12, 15, 18, 21};
    vector<int> succ3 = {3, 6, 9, 12, 15, 21};
    vector<int> succ4 = {3, 6, 9, 12, 15, 21, 24, 27};
    int n1 = find_missing_num(succ1, 0, succ1.size()-1);
    int n2 = find_missing_num(succ2, 0, succ2.size()-1);
    int n3 = find_missing_num(succ3, 0, succ3.size()-1);
    int n4 = find_missing_num(succ4, 0, succ4.size()-1);
    cout<<n1<<endl;
    cout<<n2<<endl;
    cout<<n3<<endl;
    cout<<n4<<endl;
}