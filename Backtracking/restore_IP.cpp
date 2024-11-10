#include <iostream>
#include <string>
#include <vector>

using namespace std;

void backtrack(vector<string>& output, string tmp, string s, int index, int segments){

    if(segments == 4 && index==s.size()){
        output.push_back(tmp);
        return;
    }
    if (segments >= 4 || index >= s.size()) {
        return;
    }
    for(int i = 1; i <= 3 && index + i <= s.size(); i++){
        string segment = s.substr(index, i);

        if((segment[0] == '0' && segment.size() > 1) || stoi(segment) > 255){  
            continue;
        }

        string next = tmp + (segments > 0 ? "." : "") + segment;
        backtrack(output, next, s, index+i, segments+1);   
       
    }
}

vector<string> restoreIpAddresses(string s){
    vector<string> output;
    backtrack(output, "", s, 0, 0);
    return output;
}

int main(){
    string s = "25523411135";
    vector<string> result = restoreIpAddresses(s);
    for(int i = 0; i < result.size(); i++){
        cout<<result[i]<<endl;
    }
}