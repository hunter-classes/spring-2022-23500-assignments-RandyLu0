#include <bits/stdc++.h>
using std::cout;
typedef unsigned long long ll; 

// bespoke/dp???
ll steps(ll n, ll arr[]){
    if(arr[n]) return arr[n];
    return arr[n] = (steps(n - 1, arr) % 10000000007 + steps(n - 2, arr) % 10000000007 + steps(n - 3, arr) % 10000000007) % 10000000007; 
}

ll stairs(ll n){
    ll arr[n + 1];
    for(ll i = 0; i < n + 1; i++){
        arr[i] = 0;
    }
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    return steps(n,arr);
}

//naive
int f(int n){
    if(n == 1) return 1;
    if(n ==2 ) return 2;
    if(n == 3) return 4;
    return (f(n-1) % 10000000007 + f(n-2) % 10000000007  + f(n-3) % 10000000007) % 10000000007;
}

int main(){
    cout << stairs(57) << "\n";
    cout << stairs(90) << "\n";
    return 0;
}