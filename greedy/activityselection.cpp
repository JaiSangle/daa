#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<pair<int,int>> activities(n);
    for(int i = 0; i < n; i++){
        // start, end
        cin >> activities[i].first >> activities[i].second;
    }
    sort(activities.begin(), activities.end(), [&](auto a, auto b){
        return a.second < b.second;
    });

    // complete the first activity and loop
    // check if activities[i].first (start time) >= end of cur selected [if yes then select the activity]
    auto cur = activities[0];
    int completed = 1;
    for(int i = 1; i < n; i++){
        if(activities[i].first >= cur.second){
            cur = activities[i];
            completed++;
        }
    }
    cout << completed << endl;
}