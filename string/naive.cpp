#include<bits/stdc++.h>
using namespace std;

int main(){
    string text, pattern;
    cin >> text >> pattern;

    int n = text.length(), m = pattern.length();
    if(m > n){
        cout << "not found" << endl;
        return 0;
    }

    vector<int> pos;
    auto find = [&]() -> void {
        for(int i = 0; i <= n - m; i++){
            int j = i, k = 0;
            while(j < n && k < m){
                if(text[j] != pattern[k]) break;
                j++; k++;
            }

            if(k == m){
                pos.push_back(i + 1);
            }
        }
    };
    find();

    if(pos.empty()){
        cout << "Not found" << endl;
        return 0;
    }

    for(int p : pos){
        cout << p << ' ';
    }
}