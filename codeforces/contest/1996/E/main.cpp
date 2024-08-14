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

#define cases 1
void solve() {
    string s;
    cin >> s;
    map<int, ll> m;
    ll result = 0, bal = 0;
    m[0] = 1;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c == '1') bal++;
        if (c == '0') bal--;
        result += m[bal] * (s.size() - i);
        result %= MOD;
        m[bal] += i + 2;
    }
    cout << result << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
