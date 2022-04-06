#include <iostream>
#include <vector>
using std::cout;
using std::vector;

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

int main(){
    vector<int> a;
    for(int i = 1; i < 6; i++) a.push_back(i);
    a.push_back(4);
    qsort2(a,0,a.size() - 1);
    for(auto x : a) cout << x << " ";
    cout << "\n";
    return 0;
}