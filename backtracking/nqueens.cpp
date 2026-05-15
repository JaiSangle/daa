#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;

    if(n < 4){
        cout << "Cannot place" << endl;
        return 0;
    }

    // \ diagonals have i - j const
    // / diagonals have i + j const

    vector<int> row(n, 0), col(n, 0), lrtype(2 * n, 0), rltype(2 * n, 0);
    auto check = [&](int r, int c) -> bool {
        return !row[r] && !col[c] && !lrtype[r - c + n - 1] && !rltype[r + c];
    };

    vector<vector<int>> sol;
    vector<int> cur;
    auto recurse = [&](auto&& self, int r) -> void {

        if(r == n){
            sol.push_back(cur);
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(cur[i] == j){
                        cout << "Q ";
                    }
                    else{
                        cout << ". ";
                    }
                }
                cout << endl;
            }
            cout << "---------------" << endl;
            return;
        }

        for(int i = 0; i < n; i++){
            if(check(r, i)){
                // place
                row[r] = col[i] = lrtype[r - i + n - 1] = rltype[r + i] = 1;
                cur.push_back(i);
                self(self, r + 1);
                // unplace
                row[r] = col[i] = lrtype[r - i + n - 1] = rltype[r + i] = 0;
                cur.pop_back();
            }
        }
    };
    recurse(recurse, 0);
}