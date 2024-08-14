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
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

const ll INF = 2e9, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    int R, G, B;
    cin >> R >> G >> B;
    int a;
    string s;
    cin >> s;
    a = (s == "Red" ? 0 : s == "Green" ? 1 : 2);
    if (a == 0) cout << min(G, B);
    if (a == 1) cout << min(R, B);
    if (a == 2) cout << min(R, G);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
