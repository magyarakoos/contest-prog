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
    cin >> N;
    vector<int> v(N);
    for (int& x : v) cin >> x;

    ll res = 0;
    map<array<int, 2>, ll> m_12, m_13, m_23;
    map<array<int, 3>, ll> m_123;

    for (int i = 0; i < N - 2; i++) {
        res += m_12[{v[i], v[i + 1]}]++;
        res += m_13[{v[i], v[i + 2]}]++;
        res += m_23[{v[i + 1], v[i + 2]}]++;
        res -= m_123[{v[i], v[i + 1], v[i + 2]}] * 3;
        m_123[{v[i], v[i + 1], v[i + 2]}]++;
    }

    cout << res << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}

