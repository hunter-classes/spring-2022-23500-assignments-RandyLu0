#include <vector>
#include <iostream>
#include <time.h>
#include <unistd.h>
#include <cstdlib>
#include <sys/time.h>
#include <math.h>
using std::vector;
using std::cout;

vector<int> merge(vector<int> a, vector<int> b){
    int ai = 0, bi = 0, as = a.size(), bs = b.size();
    vector<int> v;
    for (int k = 0; k < as + bs; ++k) {
        if(ai >= as) v.push_back(b[bi++]);
        else if(bi >= bs) v.push_back(a[ai++]);
        else v.push_back(a[ai] > b[bi] ? b[bi++] : a[ai++]);
    }
    return v;
}

vector<int> msort(vector<int> v){
    if(v.size() == 1) return v;
    vector<int> a; 
    vector<int> b;
    int k = v.size() / 2;
    for (int i = 0; i < v.size(); i++){
        if(i < k) a.push_back(v[i]);
        else b.push_back(v[i]);
    }
    a = msort(a);
    b = msort(b); 
    return merge(a,b);
}

int count(vector<int> v, int value){
    int freq = 0;
    for(auto i : v) freq += i == value;
    return freq;
}

int largest(vector<int> v){
    int m = v[0];
    for(auto i : v) m = m < i ? i : m;
    return m;
}

int mode(vector<int> v){
    v = msort(v);
    int m = v[0];
    int freq = 0;
    int f = 0;
    for(auto i : v){
        if (i = m) ++f;
        else{ 
            if (f > freq) m = i, freq = f;
            f = 0;
        }
    }
    return m;
}

int main(){
    int size=20;
    int max_val=100;
    srand(time(nullptr));
    std::vector<int> b(size);
    for (int i=0;i<size; i++) b[i] = rand()%max_val;
    int m = mode(b);
    cout << "mode: " << m << "\nfrequency: " << count(b,m) << "\nlargest: " << largest(b) << "\n";
    b = msort(b);
    for(auto i : b) cout << i << " ";
    cout << "\n";
    return 0;
}