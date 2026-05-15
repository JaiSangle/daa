#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, target; cin >> n >> target;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int lo = 0, hi = n - 1, idx = -1;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(a[mid] == target){
            idx = mid;
            break;
        }
        else if(a[mid] < target){
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }

    if(idx == -1){
        cout << "target not found" << endl;
        return 0;
    }

    cout << "target found at index: " << idx << endl;
}