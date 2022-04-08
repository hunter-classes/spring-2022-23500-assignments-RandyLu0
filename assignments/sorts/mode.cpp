#include <vector>
#include <iostream>
using std::vector;
using std::cout;

int count(const vector<int> &v, int value){
    int freq = 0;
    for(auto i : v) freq += i == value;
    return freq;
}

int largest(const vector<int> &v){
    int m = v[0];
    for(auto i : v) m = m < i ? i : m;
    return m;
}

int mode(const vector<int> &v){
    vector<int> freq(largest(v) + 1);
    for(auto i : v) freq[i]++;
    int m = freq[0], mode, index = 0;
    for(auto i : freq){
        if(m < i) m = i, mode = index;
        index++;
    }   
    return mode;
}

int main(){
    cout << "\n";
    return 0;
}