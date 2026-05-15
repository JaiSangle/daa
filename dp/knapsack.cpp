#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, w; cin >> n >> w;
    vector<pair<int,int>> items(n);
    for(int i = 0; i < n; i++){
        cin >> items[i].first >> items[i].second;
    }

    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= w; j++){
            int take = 0, dontTake = dp[i-1][j];
            if(j - items[i-1].second >= 0){
                take = items[i-1].first + dp[i-1][j - items[i-1].second];
            }
            dp[i][j] = max(take, dontTake);
        }
    }
    cout << dp[n][w] << endl;

    vector<int> chosen(n + 1, 0);
    int i = n, j = w;
    while(i > 0 && j > 0){
        if(dp[i][j] != dp[i-1][j]){
            chosen[i] = 1;
            j -= items[i-1].second;
        }
        i--;
    }

    for(int i = 1; i <= n; i++){
        cout << chosen[i] << ' ';
    }
}