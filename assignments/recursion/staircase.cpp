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
/*
#define M 10000000007ll

// memoized
ll steps(ll n, ll arr[]){
    if(arr[n]) return arr[n];
    return arr[n] = (steps(n - 1, arr) % M + steps(n - 2, arr) % M + steps(n - 3, arr) % M) % M; 
}

ll stairs(ll n){
    ll arr[n + 1];
    for(ll i = 1; i < n + 1; i++) arr[i] = i <= 3 ? 1 << i - 1 : 0;
    return steps(n,arr);
}

//naive
int f(int n){
    if(n <= 3) return 1 << n - 1;
    return (f(n-1) % M + f(n-2) % M + f(n-3) % M) % M;
}

//bottom-up?
ll iter(ll n){
    ll a = 1, b = 2, c = 4, s = 0;
    for (ll i = 3; i < n; i++){
        s += (a % M + b % M + c % M) % M;
        if(i == n - 1) break;
        a = b % M;
        b = c % M;
        c = s % M;
        s = 0;
    }
    return n <= 3 ? 1 << n - 1 : s;
}
*/

ll fib(ll n){
    ll a = 1, b = 1, total = 0;
    for(ll i = 0; i < n; i++){
        total += a + b;
        if(total % 10 == 7) return total;
        a = b, b = total;
    }
    return -1;
}


int main(){
    /*
    cout << stairs(11) << "\n";
    cout << iter(3) << "\n";
    cout << stairs(570) << "\n";
    cout << iter(570) << "\n";
    cout << iter(900000) << "\n";
    */
    cout << fib(1) << "\n";

    return 0;
}