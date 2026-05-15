#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

void merge(int i, int j, vector<int>& arr){
    vector<int> res(j - i + 1);
    int mid = (i + j) / 2;
    int l = i, r = mid + 1, k = 0;
    while(l <= mid && r <= j){
        if(arr[l] <= arr[r]){
            res[k++] = arr[l];
            l++;
        }
        else{
            res[k++] = arr[r];
            r++;
        }
    }

    while(l <= mid){
        res[k++] = arr[l++];
    }

    while(r <= j){
        res[k++] = arr[r++];
    }

    int p = i, q = 0;
    while(p <= j){
        arr[p++] = res[q++];
    }
}

void sort(int low, int high, vector<int>& arr){

    if(low >= high){
        return;
    }

    int mid = (low + high) / 2;
    sort(low, mid, arr);
    sort(mid + 1, high, arr);
    merge(low, high, arr);
}

int main(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
       cin >> arr[i];
    }

    sort(0, n - 1, arr);

    for(int i : arr){
        cout << i << ' ';
    }
}