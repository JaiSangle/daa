#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define int long long

signed main(){

    
    string text, pattern;
    cin >> text >> pattern;
    
    auto start = high_resolution_clock::now();
    
    int n = text.length(), m = pattern.length();
    if(m > n){
        cout << "not possible" << endl;
        return 0;
    }

    // pattern hash (31, 37)
    int prime1 = 1e9 + 7, prime2 = 1e9 + 9, p = 31;
    vector<int> patternHash(2);
    for(int i = 0; i < m; i++){
        patternHash[0] = (patternHash[0] * p + (pattern[i] - 'a' + 1)) % prime1;
        patternHash[1] = (patternHash[1] * p + (pattern[i] - 'a' + 1)) % prime2;
    }

    // first window
    int rollingHash1 = 0, rollingHash2 = 0;
    for(int i = 0; i < m; i++){
        rollingHash1 = (rollingHash1 * p + text[i] - 'a' + 1) % prime1;
        rollingHash2 = (rollingHash2 * p + text[i] - 'a' + 1) % prime2;
    }

    vector<int> sol;
    if(rollingHash1 == patternHash[0] && rollingHash2 == patternHash[1]){
        sol.push_back(1);
    }

    auto bexpo = [&](int a, int b, int mod) -> int {
        // a ^ b
        int res = 1;
        while(b > 0){
            if(b & 1){
                res = (res * a) % mod;
            }
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    };
    
    int pow1 = bexpo(p, m - 1, prime1), pow2 = bexpo(p, m - 1, prime2);
    for(int i = m; i < n; i++){
        // leaving: i - m, entering: i
        
        rollingHash1 = ((rollingHash1 - pow1 * (text[i-m] - 'a' + 1)) % prime1 + prime1) % prime1;
        rollingHash1 = (rollingHash1 * p + text[i] - 'a' + 1) % prime1;

        rollingHash2 = ((rollingHash2 - pow2 * (text[i-m] - 'a' + 1)) % prime2 + prime2) % prime2;
        rollingHash2 = (rollingHash2 * p + text[i] - 'a' + 1) % prime2;

        if(rollingHash1 == patternHash[0] && rollingHash2 == patternHash[1]){
            int p = i - m + 1, q = 0, ok = 1;
            while(p < n && q < m){
                if(text[p] != pattern[q]){
                    ok = 0;
                    break;
                }
                p++; q++;
            }

            if(ok){
                sol.push_back(i - m + 2);
            }
        }
    }

    if(sol.empty()){
        cout << "pattern not found in text" << endl;
        return 0;
    }

    for(int p : sol){
        cout << p << ' ';
    }
    cout << endl;

    auto end = high_resolution_clock::now();

    duration<double, milli> diff = end - start;
    cout << "time take: " << diff.count() << endl;
}