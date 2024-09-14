#include <bits/stdc++.h>
#ifdef LOCAL
#include <debug.h>
#else
#define DB(...)
#endif

using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) (int)v.size()

const ll INF = 2e9, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    string s, t;
    cin >> s >> t;
    vector<string> a;
    int N = sz(s);
    for (int i = 0; i < N; i++) {
        string nxt = string(101, 'z');
        for (int j = 0; j < N; j++) {
            if (s[j] != t[j]) {
                char tmp = s[j];
                s[j] = t[j];
                nxt = min(nxt, s);
                s[j] = tmp;
            }
        }
        if (nxt == string(101, 'z')) { break; }
        s = nxt;
        a.push_back(nxt);
    }
    cout << sz(a) << "\n";
    for (const string& sx : a) cout << sx << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
