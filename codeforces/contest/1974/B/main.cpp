#include <bits/stdc++.h>
#ifdef LOCAL
#include <magyarakoos-debug.h>
#else
#define DB(...)
#endif
using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) (int)v.size()
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

const ll INF = 2e9, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 1
void solve() {
    int N;
    string s;
    cin >> N >> s;
    string h;
    for (char c : s) {
        if (h.find(c) == h.npos) {
            h.push_back(c);
        }
    }
    sort(all(h));
    DB(sz(h));
    for (char& c : s) {
        int i = h.find(c);
        int rev = sz(h) - i - 1;
        DB(c,i,rev);
        c = h[rev];
    }
    cout << s << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
