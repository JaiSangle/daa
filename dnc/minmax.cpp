#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define int long long

int32_t main(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int mn = 1e9, mx = -1e9, comparisons = 0;
    auto minmax = [&](auto&& self, int i, int j, int& mn, int& mx) -> void {
        if(j - i == 0){
            mn = a[j];
            mx = a[j];
        }
        else if(j - i == 1){
            if(a[j] > a[i]){
                mn = a[i];
                mx = a[j];
            }
            else{
                mn = a[j];
                mx = a[i];
            }
        }
        else{
            int mid = (i + j) / 2;

            int leftMin = 1e9, leftMax = -1e9;
            int rightMin = 1e9, rightMax = -1e9;

            self(self, i, mid, leftMin, leftMax);
            self(self, mid + 1, j, rightMin, rightMax);

            comparisons++;
            mn = min(leftMin, rightMin);
            comparisons++;
            mx = max(leftMax, rightMax);
        }
    };
    minmax(minmax, 0, n - 1, mn, mx);

    cout << mn << ' ' << mx << ' ' << comparisons << endl;
}