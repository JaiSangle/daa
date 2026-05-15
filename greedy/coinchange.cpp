#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, amount;
    cin >> n >> amount;
    vector<int> coins(n);
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }
    sort(coins.begin(), coins.end(), greater<int>());
    
    int ct = 0, rem = amount;
    vector<int> seq;
    for(int coin : coins){
        while(coin <= rem){
            rem -= coin;
            ct++;
            seq.push_back(coin);
        }
    }

    if(rem == 0){
        cout << ct << endl;
        for(int i : seq){
            cout << i << ' ';
        }
    }
    else{
        cout << "the amount cannot be obtained using the given coins" << endl;
    }
}