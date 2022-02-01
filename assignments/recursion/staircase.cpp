/*
Determine the amount of lists whose sum is positive integer n
and whose elements are in the set {1, 2, 3} modulo 10^10 + 7.

ex) n = 5 has 13 lists

1 1 1 1 1
1 2 1 1
1 1 2 1
1 1 1 2
1 3 1
1 1 3
1 2 2

2 1 2
2 2 1
2 3
2 1 1 1

3 1 1 
3 2 
*/

#include <bits/stdc++.h>
using std::cout;
typedef unsigned long long ll; 

// memoized
ll steps(ll n, ll arr[]){
    if(arr[n]) return arr[n];
    return arr[n] = (steps(n - 1, arr) % 10000000007ll + steps(n - 2, arr) % 10000000007ll + steps(n - 3, arr) % 10000000007ll) % 10000000007ll; 
}

ll stairs(ll n){
    ll arr[n + 1];
    for(ll i = 0; i < n + 1; i++) arr[i] = 0;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    return steps(n,arr);
}

//naive
int f(int n){
    if(n == 1) return 1;
    if(n == 2) return 2;
    if(n == 3) return 4;
    return (f(n-1) % 10000000007ll + f(n-2) % 10000000007ll  + f(n-3) % 10000000007ll) % 10000000007ll;
}

int main(){
    cout << stairs(5) << "\n";
    cout << stairs(57) << "\n";
    cout << stairs(90000) << "\n";
    return 0;
}