#include<bits/stdc++.h>
using namespace std;

#define int long long

const int inf = 1e9;

signed main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n + 1, vector<int>(n + 1,inf));
    for(int i = 0; i < m; i++){
        int u,v,wt; cin >> u >> v >> wt;
        adj[u][v] = min(adj[u][v], wt);
        adj[v][u] = min(adj[v][u], wt);
    }

    for(int i = 1; i <= n; i++){
        adj[i][i] = 0;
    }

    auto d = adj;
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(d[i][k] < inf && d[k][j] < inf) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << (d[i][j] < inf ? d[i][j] : -1) << " \n"[j == n];
        }
        cout << "\n";
    }
}