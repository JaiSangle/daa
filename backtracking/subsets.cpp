#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, target; cin >> n >> target;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<vector<int>> sol;
    vector<int> cur;
    auto recurse = [&](auto&& self, int curSum, int idx) -> void {
        if(curSum == target){
            sol.push_back(cur);
            for(int i : cur){
                cout << i << ' ';
            }
            cout << endl;
            return;
        }

        if(idx == n){
            return;
        }

        // take cur
        cur.push_back(a[idx]);
        self(self, curSum + a[idx], idx + 1);
        cur.pop_back();
        // dont take cur
        self(self, curSum, idx + 1);
    };
    recurse(recurse, 0, 0);
}