#include <iostream>

using namespace std;

bool found_solution = false;

bool is_a_solution(int maze[][4], int mouse_row, int mouse_col){
    if(mouse_row == 3 && mouse_col == 3){
        return true;
    }
    else{
        return false;
    }
}

void process_solution(int output[][4]){
    cout<<"Mouse path:"<<endl;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cout<<output[i][j];
        }
        cout<<endl;
    }
}

bool is_safe(int maze[][4], int mouse_row, int mouse_col) {
    // Controlla che la cella sia dentro i limiti e accessibile (valore 1)
    if(mouse_row >= 0 && mouse_row < 4 && mouse_col >= 0 && mouse_col < 4 && maze[mouse_row][mouse_col] == 1){
        return true;
    }
    else{
        return false;
    }
}

bool make_move(int output[][4], int maze[][4], int &mouse_row, int &mouse_col){
    cout<<"current mouse position: "<<mouse_row<<", "<<mouse_col<<endl;
    if(is_safe(maze, mouse_row, mouse_col + 1) && output[mouse_row][mouse_col + 1] == 0){
        output[mouse_row][mouse_col+1]=1;
        mouse_col++;
        return true;
    }
    else if(is_safe(maze, mouse_row + 1, mouse_col) && output[mouse_row + 1][mouse_col] == 0){
        output[mouse_row+1][mouse_col]=1;
        mouse_row++;
        return true;
    }
    // Move Left
    else if(is_safe(maze, mouse_row, mouse_col - 1) && output[mouse_row][mouse_col - 1] == 0) {
        output[mouse_row][mouse_col - 1] = 1;
        mouse_col--;
        return true;
    }
    // Move Up
    else if(is_safe(maze, mouse_row - 1, mouse_col) && output[mouse_row - 1][mouse_col] == 0) {
        output[mouse_row - 1][mouse_col] = 1;
        mouse_row--;
        return true;
    }
    return false;
}

void unmake_move(int output[][4], int maze[][4], int &mouse_row, int &mouse_col){
    cout<<"Sono in UNMAKE"<<endl;
    cout<<mouse_row<<" "<<mouse_col<<endl;
    if(is_safe(maze, mouse_row, mouse_col - 1) && output[mouse_row][mouse_col - 1] == 1){
        output[mouse_row][mouse_col]=0;
        //maze[mouse_row][mouse_col]=0;
        mouse_col--;
    }
    else if(is_safe(maze, mouse_row - 1, mouse_col) && output[mouse_row - 1][mouse_col] == 1){
        output[mouse_row][mouse_col]=0;
        //maze[mouse_row][mouse_col]=0;
        mouse_row--;
    }
    if(is_safe(maze, mouse_row, mouse_col + 1) && output[mouse_row][mouse_col + 1] == 1) {
        output[mouse_row][mouse_col]=0;
        mouse_col++;
    }
    // Check and undo move Up
    else if(is_safe(maze, mouse_row + 1, mouse_col) && output[mouse_row + 1][mouse_col] == 1) {
        output[mouse_row][mouse_col]=0;
        mouse_row++;
    }
    return;
}

void backtrack(int output[][4], int maze[][4], int &mouse_row, int &mouse_col){
    if(found_solution) return;

    if(is_a_solution(maze, mouse_row, mouse_col)){
        process_solution(output);
        found_solution = true;
    }
    else{   
        if(make_move(output, maze, mouse_row, mouse_col)){
            backtrack(output, maze, mouse_row, mouse_col);
            unmake_move(output, maze, mouse_row, mouse_col);
        }       
    }
}

int main(){
    cout<<"Structure of the maze:"<<endl;
    
    int maze[4][4]={1,1,1,0,1,1,0,1,0,1,0,0,1,1,1,1};
    int output[4][4]={1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cout<<maze[i][j];
        }
        cout<<endl;
    }
    cout<<"------------"<<endl;

    int mouse_row=0;
    int mouse_col=0;

    backtrack(output, maze, mouse_row, mouse_col);

}
