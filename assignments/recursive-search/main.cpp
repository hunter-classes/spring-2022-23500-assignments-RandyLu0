#include <iostream>
#include <unistd.h>
using std::cout;


const int n = 5;
bool done = false;

int arr[n][n];

void init(){
    for(int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            arr[i][j] = 0;
}

void print(int x, int y){
    //cout << "[0;0H\n";
    cout << "_______________\n";    //ansi escape idk
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == x and j == y) cout << " N" << "|";
            else if(arr[i][j] >= 10) cout << arr[i][j] <<"|";
            else cout << " " << arr[i][j] << "|";
        }  
        cout << "\n";   
    }
}

bool check(){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if(arr[i][j] == 0) return false;        
    return true;
}
    

void move(int x, int y, int i){
    arr[x][y] = i;
    //usleep(1000000);
     if (check()){
        done = true;
        print(x,y);
        return;
    }
    if(x + 2 < n and y + 1 < n and !arr[x+2][y+1] and !done) move(x+2,y+1,i+1);
    if(x + 2 < n and y - 1 >= 0 and !arr[x+2][y-1] and !done) move(x+2,y-1,i+1);
    if(x + 1 < n and y + 2 < n and !arr[x+1][y+2] and !done) move(x+1,y+2,i+1);
    if(x + 1 < n and y -2 >= 0 and !arr[x+1][y-2] and !done) move(x+1,y-2,i+1);
    if(x - 2 >= 0 and y + 1 < n and !arr[x-2][y+1] and !done) move(x-2,y+1,i+1);
    if(x - 2 >= 0 and y - 1 >= 0 and !arr[x-2][y-1] and !done) move(x-2,y-1,i+1);
    if(x -1 >= 0 and y + 2 < n and !arr[x-1][y+2] and !done) move(x-1,y+2,i+1);
    if(x -1 >= 0 and y -2 >= 0 and !arr[x-1][y-2] and !done) move(x-1,y-2,i+1);
    arr[x][y] = 0;
    return;
}




int main(){
    init();
    move(0,0,1);
    cout << done << "\n";
    return 0;
}