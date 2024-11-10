#include <iostream>
#include <vector>

using namespace std;

vector<string> letters = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void make_move(string digits){
    if(digits.size()==0){
        cout<<"[]"<<endl;
    }
    else if(digits.size()==1){
        vector<char> output;
        cout<<"[";
        for(int i=0; i<digits.size(); i++){
            int index = digits[i]-'2';
            for(int j=0; j<letters[index].size(); j++){
                char ch = letters[index][j];
                output.push_back(ch);
                cout<<"\""<<output[j]<<"\",";
            }
        }
        cout<<"]"<<endl;
    }
    else{
        vector<string> output;
        
    }
    return;
}

void letter_combination(string digits){
    make_move(digits);
}

int main(){
    string digits0 = "";
    string digits1 = "2";
    string digits2 = "23";
    string digits3 = "234";
    string digits4 = "2345";
    letter_combination(digits0);
    letter_combination(digits1);
    //letter_combination(digits2);
}