#include <iostream>
#include <vector>
#include <random>
using std::cout;
using std::vector;

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

void qsort2(vector<int> &list, int low, int high){
    if(high - low + 1 == 0) return;

    int lo = low, hi = high;    


    //determines the pivot using median 
    int pivot, mid = (low + high) / 2;
    int h = list[high], l = list[low], m = list[mid];

    
    if((l > m and l < h) or (l < m and l > h)) pivot = low;
    else if((h > m and h < l) or (h < m and h > l)) pivot = high;
    else pivot = mid;

    int p = list[pivot];

    //sorts about pivot
    while(low <= high){
        l = list[low], h = list[high];

        if(l > p and pivot > low){
            list[low] = p, list[pivot] = l; 
            pivot = low++;
        }else if(pivot >= low) ++low;
        
        if(h < p and pivot < high){
            list[high] = p, list[pivot] = h;
            pivot = high--;
        }else if(high >= pivot) --high;
    }

    qsort2(list, lo, pivot - 1);
    qsort2(list, pivot + 1, hi);
}

vector<int> qsort(vector<int> list){
    if(list.size() <= 1) return list;
    vector<int> a, b;
    for (int i = 1; i < list.size(); i++){
        if(list[i] < list[0]) a.push_back(list[i]);
        else b.push_back(list[i]);
    }
    a = qsort(a);
    b = qsort(b);
    a.push_back(list[0]);
    for(auto i : b) a.push_back(i);
    return a;
}

int main(){
    std::random_device rd;
    int size=10e6;
    int max_val=10e5;
    std::vector<int> b(size);
    for (int i=0;i<size; i++) b[i] = rd() % max_val;
    qsort2(b,0,b.size() - 1); 
    return 0;
}