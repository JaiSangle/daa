#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define int long long

signed main(){
    int n; cin >> n;
    vector<int> p(n+1), q(n+1);
    p[0] = 0;
    // successful: p (n)
    for(int i = 1; i <= n; i++){
        cin >> p[i];
    }
    // unsuccessful: q (n + 1)
    for(int i = 0; i <= n; i++){
        cin >> q[i];
    }

    auto start = high_resolution_clock::now();
    vector<vector<int>> w(n + 1, vector<int>(n + 1)), r(n + 1, vector<int>(n + 1)), c(n + 1, vector<int>(n + 1, 1e9));
    for(int i = 0; i <= n; i++){
        w[i][i] = q[i];
        r[i][i] = 0;
        c[i][i] = 0;
    }

    for(int diff = 1; diff <= n; diff++){
        for(int i = 0; i + diff <= n; i++){
            int j = i + diff;
            w[i][j] = w[i][j-1] + p[j] + q[j];
            for(int k = i + 1; k <= j; k++){
                int cost = c[i][k-1] + c[k][j] + w[i][j];
                if(cost < c[i][j]){
                    c[i][j] = cost;
                    r[i][j] = k;
                }
            }
        }
    }
    cout << c[0][n] << endl;

    auto print = [&](auto&& self, int i, int j) -> void {
        if(i >= j) return;

        cout << r[i][j] << ' ';
        self(self, i, r[i][j] - 1);
        self(self, r[i][j], j);
    };
    print(print,0,n);
    cout << endl;

    auto end = high_resolution_clock::now();

    duration<double, milli> elapsed = end - start;
    cout << elapsed.count() << endl;
}