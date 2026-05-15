#include<bits/stdc++.h>
using namespace std;

int main(){
    string text, pattern; cin >> text >> pattern;

    int n = text.length(), m = pattern.length();
    vector<int> last(256, -1);
    for(int i = 0; i < m; i++){
        // assuming only abcd...z
        last[pattern[i]] = i;
    }

    vector<int> sol;
    int i = m - 1;
    while(i < n){
        int j = m - 1;
        while(j >= 0 && text[i - m + 1 + j] == pattern[j]){
            j--;
        }

        if(j < 0){
            sol.push_back(i - m + 1);
            i += m;
        }
        else{
            i += max(1, j - last[text[i - m + 1 + j]]);
        }
    }

    if(sol.empty()){
        cout << "not found" << endl;
        return 0;
    }

    for(int pos : sol){
        cout << pos << ' ';
    }
}