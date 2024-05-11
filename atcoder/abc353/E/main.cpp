#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) (int)v.size()
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

const ll INF = 2e9, MAXN = 3e5, MOD = 1e9 + 7;

int node_count = 1, trie[MAXN + 1][26], cnt[MAXN + 1];
ll res = 0;

void insert(const string& s) {
    int node = 1;
    for (char c : s) {
        int i = c - 'a';
        if (!trie[node][i]) {
            trie[node][i] = ++node_count;
        }
        node = trie[node][i];
        res += cnt[node]++;
    }
}

#define cases 0
void solve() {
    int N;
    cin >> N;
    vector<string> v(N);
    for (string& e : v) cin >> e, insert(e);
    cout << res;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}