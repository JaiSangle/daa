#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int main(){
    int n; cin >> n;
    vector<vector<int>> cost(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> cost[i][j];
        }
    }

    vector<vector<int>> dp(1 << n, vector<int>(n,1e9)), parent(1 << n, vector<int>(n,-1));
    vector<int> reachedFrom(n,-1);
    dp[1][0] = 0;
    for(int mask = 0; mask < (1 << n); mask++){
        for(int i = 0; i < n; i++){
            if((mask >> i) & 1){
                for(int j = 0; j < n; j++){
                    if(i != j && ((mask >> j) & 1)){
                        int newCost = dp[mask ^ (1 << i)][j] + cost[j][i];
                        if(newCost < dp[mask][i]){
                            parent[mask][i] = j;
                            dp[mask][i] = newCost;
                        }
                    }
                }
            }
        }
    }

    int ans = 1e9, last;
    for(int i = 1; i < n; i++){
        int c = dp[(1 << n) - 1][i] + cost[i][0];
        if(c < ans){
            last = i;
            ans = c;
        }
    }

    cout << ans << endl;

    int cur = last, mask = (1 << n) - 1;
    vector<int> path;
    while(cur != -1){
        path.push_back(cur);
        int prev = parent[mask][cur];
        mask ^= 1 << cur;
        cur = prev;
    }
    reverse(path.begin(), path.end());
    for(int p : path){
        cout << p << ' ';
    }
}