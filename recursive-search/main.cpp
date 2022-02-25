#include <iostream>
using std::cout;

const int n = 5;
bool done = false;
int arr[n][n];

void init(){ 
    for(int i = 0; i < n; i++) for (int j = 0; j < n; j++) arr[i][j] = 0; 
    done = false;
}

void print(int x, int y){
    cout << "_______________\n";   
    for(int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
            if(arr[i][j] >= 10) cout << arr[i][j] <<"|";
            else cout << " " << arr[i][j] << "|";
            if(j + 1 == n) cout << "\n";
        }   
}

bool check(){
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if(arr[i][j] == 0) return false;        
    return true;
}
    
void move(int x, int y, int i){
    arr[x][y] = i;
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
}

int main(){
    cout << "All possible Knights Tour on 5x5 board\n"; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
        init();
        move(i,j,1);
        }
    }
    return 0;
}