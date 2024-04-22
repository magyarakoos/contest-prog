#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 5e5;
#define has(s, x) s.count(x)

map<char, int> trie[MAXN];
int cnt[MAXN];
int node_count = 1;
set<string> words;

string curr;
void solve(int node, set<string>& res) {
    if (has(words, curr)) {
        res.insert(curr);
    }
    for (auto [c, v] : trie[node]) {
        curr += c;
        solve(trie[node][c], res);
        curr.pop_back();
    }
}

int main() {
	cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;
    while (N--) {
        string s;
        cin >> s;
        words.insert(s);
        int node = 1;
        for (char c : s) {
            if (!has(trie[node], c)) {
                node_count++;
                trie[node][c] = node_count;
            }
            node = trie[node][c];
            cnt[node]++;
        }
    }
    int K;
    cin >> K;
    for (int i = 1; i <= K; i++) {
        cout << "Case #" << i << ":\n";

        set<string> res;
        int node = 1;
        string s;
        cin >> s;

        for (char c : s) {
            if (!has(trie[node], c)) {
                goto nomatch;
            }
            node = trie[node][c];
        }
        
        if (!trie[node].empty()) {
            curr = s;
            solve(node, res);
        }

        res.erase(s);

        if (res.empty()) {
            nomatch:
            cout << "No match.\n";
        } else {
            for (const string& t : res)  {
                cout << t << "\n";
            }
        }
    }
}
