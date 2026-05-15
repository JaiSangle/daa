#include<iostream>
#include<vector>
#include<map>

using namespace std;

map<char, int> badChar(string s) {

    int n = s.length();
    map<char, int> bc;
    for (int i = 0; i < n; i++) {
        bc[s[i]] = max(1, n - i - 1);
    }

    return bc;
}

vector<int> goodSuf(string s) {

    int n = s.length();
    vector<int> gs(n+1, 0);
    gs[n] = 1;

    for (int i = 1; i < n; i++) {
        vector<pair<string, int>> pref, suf;

        for (int j = 3; j <= n-i; j++) {
            pref.push_back({s.substr(i, j), i});
        }

        for (int j = i; j < n; j++) {
            suf.push_back({s.substr(j), j});
        }

        for (int j = 0; j < pref.size(); j++) {
            for (int k = 0; k < suf.size(); k++) {
                if (pref[j].first == suf[k].first) {
                    gs[suf[k].second] = gs[suf[k].second] ? min(gs[suf[k].second], suf[k].second - pref[j].second) : (suf[k].second - pref[j].second);
                }
            }
        }
    }

    vector<pair<string, int>> pref, suf;
    for (int j = 1; j < n; j++) {
        pref.push_back({s.substr(0, j), 0});
    }
    for (int j = 0; j < n; j++) {
        suf.push_back({s.substr(j), j});
    }
    int len = 0, idx = n;
    string lps = "";
    for (int j = 0; j < pref.size(); j++) {
        for (int k = 0; k < suf.size(); k++) {
            if (pref[j].first == suf[k].first and suf[k].first.length() > len) {
                len = suf[k].first.length();
                lps = suf[k].first;
                idx = suf[k].second;
            }
        }
    }

    for (int& val: gs) {
        if (val == 0) {
            val = idx;
        }
    }

    return gs;
}

void boyer(string str, string pat) {

    map<char, int> bc = badChar(pat);
    vector<int> gs = goodSuf(pat);

    int N = str.length(), M = pat.length();

    int s = 0;
    while (s <= N - M) {
        int j = M-1;
        while (j >= 0 and str[s+j] == pat[j]) {
            j--;
        }

        if (j < 0) {
            cout << s << " ";
            s += gs[0];
        } else {
            int bad = bc[str[s+j]] ? bc[str[s+j]] : M;
            int good = gs[j+1];
            s += max(good, bad);
        }
    }
}


int main() {
   
   string str = "ADITYABAWLIGEND", s = "ADITYA";

   boyer(str, s);

}