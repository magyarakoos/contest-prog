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
    int N, Q;
    cin >> N >> Q;
    string s, t;
    cin >> s >> t;
    vector<array<int, 26>> ps(N + 1, {0}), pt(N + 1, {0});
    for (int i = 1; i <= N; i++) {
        ps[i] = ps[i - 1];
        pt[i] = pt[i - 1];
        ps[i][s[i - 1] - 'a']++;
        pt[i][t[i - 1] - 'a']++;
    }

    while (Q--) {
        int l, r;
        cin >> l >> r;
        array<int, 26> cs = ps[r], ct = pt[r];
        for (int i = 0; i < 26; i++) {
            cs[i] -= ps[l - 1][i];
            ct[i] -= pt[l - 1][i];
        }

        int result = 0;
        for (int i = 0; i < 26; i++) {
            result += abs(cs[i] - ct[i]);
        }
        cout << result / 2 << "\n";
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
