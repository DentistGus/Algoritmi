#include <iostream>

using namespace std;

void triangle(int n){
    int arr[n][n] = {0};

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            if(i == 0 || i == j){
                arr[i][j]=1;
            }
            else{
                arr[i][j]=(arr[i-1][j]+arr[i-1][j-1]);
            }
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

}

int main(){
    int n = 10;
    triangle(n);
}