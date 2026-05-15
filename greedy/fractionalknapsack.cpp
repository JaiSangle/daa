#include<bits/stdc++.h>
using namespace std;

int main(){
    // we are given the number of items (n) and the capacity of knapsack (w)
    // items have profit and weight
    int n; cin >> n;
    double w; cin >> w;
    vector<pair<double, double>> items(n);
    for(int i = 0; i < n; i++){
        // value, weight
        cin >> items[i].first >> items[i].second;
    }
    sort(items.begin(), items.end(), [&](auto a, auto b){
        return a.first / a.second > b.first / b.second;
    });

    double curCapacity = w, i = 0, profit = 0;
    while(i < n && curCapacity > 0){
        if(items[i].second > curCapacity){
            profit += (curCapacity * items[i].first) / items[i].second;
            curCapacity = 0;
        }
        else{
            profit += items[i].first;
            curCapacity -= items[i].second;
        }
        i++;
    }
    cout << profit << endl;
}