#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> d(n+1);
    for(int i = 0; i < n + 1; i++){
        cin >> d[i];
    }

    // m[i][j] = min i <= k < j (m[i][k] + m[k+1][j] + d[i-1] * d[k] * d[j])
    vector<vector<int>> m(n + 1,vector<int>(n + 1,1e9));
    for(int i = 0; i <= n; i++){
        m[i][i] = 0;
    }

    vector<vector<int>> split(n + 1, vector<int>(n + 1));
    for(int diff = 1; diff <= n; diff++){
        for(int i = 1; i + diff <= n; i++){
            int j = i + diff;
            for(int k = i; k < j; k++){
                int cost = m[i][k] + m[k+1][j] + (d[i-1] * d[k] * d[j]);
                if(cost < m[i][j]){
                    split[i][j] = k;
                    m[i][j] = cost;
                }
            }
        }
    }
    cout << m[1][n] << endl;

    auto parenthesize = [&](auto&& self, int i, int j) -> void {
        if(i == j){
            cout << "A" << i << ' ';
            return;
        }

        cout << "(";
        self(self, i, split[i][j]);
        self(self, split[i][j] + 1, j);
        cout << ")";
    };
    parenthesize(parenthesize, 1, n);
}