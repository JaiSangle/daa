#include<bits/stdc++.h>
using namespace std;

struct job {
    int profit, deadline, id;
};

int main(){
    int n; cin >> n;
    int mxDeadline = 0;
    // profit, deadline, id
    vector<job> jobs(n);
    for(int i = 0; i < n; i++){
        cin >> jobs[i].profit >> jobs[i].deadline;
        jobs[i].id = i + 1;
        mxDeadline = max(mxDeadline, jobs[i].deadline);
    }
    sort(jobs.begin(), jobs.end(), [](const job& a, const job& b){
        return a.profit > b.profit;
    });

    int ct = 0, profit = 0;
    vector<int> slot(mxDeadline + 1, 0);
    for(int i = 0; i < n; i++){
        for(int j = jobs[i].deadline; j >= 1; j--){
            if(!slot[j]){
                ct++;
                profit += jobs[i].profit;
                slot[j] = jobs[i].id;
                break;
            }
        }
    }

    cout << ct << ' ' << profit << endl;
    for(int i = 1; i <= mxDeadline; i++){
        cout << slot[i] << " \n"[i == mxDeadline];
    }
}