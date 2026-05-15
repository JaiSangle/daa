#include<bits/stdc++.h>
using namespace std;

struct node {
    int freq;
    char c;
    node *left, *right;
};

int main(){
    string s; cin >> s;
    vector<int> fq(26,0);
    for(char c : s){
        fq[c - 'a']++;
    }

    auto cmp = [&](node* a, node* b) -> bool {
        return a->freq > b->freq;
    };

    priority_queue<node*, vector<node*>, decltype(cmp)> pq(cmp);
    for(int i = 0; i < 26; i++){
        if(fq[i] > 0){
            node* cur = new node();
            cur->freq = fq[i];
            cur->c = char(i + 'a');
            cur->left = cur->right = nullptr;
            pq.push(cur);
        }
    }

    auto merge = [&](node* a, node* b) -> node* {
        node* c = new node();
        c->freq = a->freq + b->freq;
        c->c = '\0';
        c->left = a;
        c->right = b;
        return c;
    };

    while(pq.size() > 1){
        auto f = pq.top();
        pq.pop();
        auto s = pq.top();
        pq.pop();

        pq.push(merge(f,s));
    }

    auto root = pq.top();
    pq.pop();

    string code;
    map<char, string> mp;
    auto traverse = [&](auto&& self, node* root) -> void {
        // left: 0, right: 1
        if(root->left == nullptr && root->right == nullptr){
            mp[root->c] = code;
            return;
        }

        if(root->left != nullptr){
            code.push_back('0');
            self(self, root->left);
            code.pop_back();
        }

        if(root->right != nullptr){
            code.push_back('1');
            self(self, root->right);
            code.pop_back();
        }
    };
    traverse(traverse, root);

    for(auto x : mp){
        cout << x.first << ' ' << x.second << endl;
    }
}