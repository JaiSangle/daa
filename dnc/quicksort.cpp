#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int low, int high){
    int pivot = arr[high], i = low - 1;
    for(int j = low; j < high; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i + 1;
}

void quicksort(vector<int>& arr, int low, int high){
    if(low >= high) return;

    int pidx = partition(arr, low, high);
    quicksort(arr, low, pidx - 1);
    quicksort(arr, pidx + 1, high);
}

int main(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    quicksort(a, 0, n - 1);
    for(int i : a){
        cout << i << ' ';
    }
}