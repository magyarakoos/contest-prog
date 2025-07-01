#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 1e6 + 1, MOD = 1e9 + 7;

#define cases 0
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    vector<vector<int>> p(MAXN), pi(MAXN);
    for (int i = 0; i < n; i++) p[a[i]].push_back(i);
    for (int i = 1; i < MAXN; i++) {
        for (int j = 0, k = 0; j < p[i].size(); j++) {
            k = max(k, j);
            while (k < p[i].size() - 1 &&
                   p[i][k] + 1 == p[i][k + 1])
                k++;
            pi[i].push_back(p[i][k] + 1);
        }
    }

    while (m--) {
        int l, r, x;
        cin >> l >> r >> x;
        l--, r--;
        auto it = lower_bound(p[x].begin(), p[x].end(), l);
        if (a[l] != x || it == p[x].end()) {
            cout << l + 1 << "\n";
            continue;
        }
        int i = it - p[x].begin();
        if (pi[x][i] == n || pi[x][i] > r) {
            cout << "-1\n";
        } else {
            cout << pi[x][i] + 1 << "\n";
        }
    }
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
