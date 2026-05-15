#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int main(){
    int n, amount; cin >> n >> amount;
    vector<int> coins(n);
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }

    vector<int> dp(amount + 1, inf), first(amount + 1, -1);
    dp[0] = 0;
    for(int i = 0; i <= amount; i++){
        if(dp[i] == inf) continue;

        for(int coin : coins){
            if(i + coin <= amount){
                if(1 + dp[i] < dp[i + coin]){
                    first[i + coin] = coin;
                }
                dp[i + coin] = min(dp[i + coin], 1 + dp[i]);
            }
        }
    }

    if(dp[amount] >= inf){
        cout << "Amount cannot be obtained using the given coins" << endl;
        return 0;
    }
    cout << dp[amount] << endl;

    vector<int> coinsChosen;
    int i = amount;
    while(first[i] != -1){
        cout << first[i] << endl;
        coinsChosen.push_back(first[i]);
        i -= first[i];
    }
}