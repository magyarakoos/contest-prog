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

const ll INF = 2e9 + 1, MAXN = 2e5, MOD = 1e9 + 7;

vector<vector<int>> g;
vector<ll> a;

bool dfs(int u, ll x) {
    if (x >= INF) return 0;
    if (g[u].empty()) return a[u] >= x;

    for (int v : g[u]) {
        if (a[v] >= x) {
            if (!dfs(v, x)) {
                return 0;
            }
        } else {
            if (!dfs(v, x + (x - a[v]))) {
                return 0;
            }
        }
    }
    return 1;
}

bool f(ll x) { return !dfs(1, x - a[1]); }

#define cases 1
void solve() {
    int N;
    cin >> N;
    a.assign(N + 1, 0);
    g.assign(N + 1, vector<int>());

    for (int u = 1; u <= N; u++) cin >> a[u];
    for (int u = 2; u <= N; u++) {
        int p;
        cin >> p;
        g[p].push_back(u);
    }

    ll l = -1, r = INF;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (f(m)) {
            r = m;
        } else {
            l = m;
        }
    }

    cout << l << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
