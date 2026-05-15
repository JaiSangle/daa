#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int main(){
    string text, pattern; cin >> text >> pattern;
    int n = text.length(), m = pattern.length();

    if(m > n){
        cout << "not possible" << endl;
        return 0;
    }

    vector<int> lps(m + 1);
    lps[0] = 0;
    int len = 0, i = 1;
    while(i < m){
        if(pattern[len] == pattern[i]){
            lps[i] = len + 1;
            len++; i++;
        }
        else if(len > 0){
            len = lps[len - 1];
        }
        else{
            i++;
        }
    }

    vector<int> sol;
    i = 0;
    int j = 0;
    while(i < n){
        if(text[i] == pattern[j]){
            i++; j++;
        }
        else if(j == 0){
            i++;
        }
        else{
            j = lps[j-1];
        }

        if(j == m){
            sol.push_back(i - m + 1);
            j = lps[j-1];
        }
    }

    if(sol.empty()){
        cout << "pattern not found in text" << endl;
        return 0;
    }

    for(int p : sol){
        cout << p << ' ';
    }
}