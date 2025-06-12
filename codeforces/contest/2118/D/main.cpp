#include <bits/stdc++.h>
using namespace std;
#define int int64_t

#define cases 1
void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> p(n), d(n);
    for (int& x : p) cin >> x;
    for (int& x : d) cin >> x;

    vector dp(n,
              vector<vector<int>>(k, vector<int>(2, -1))),
        visj(n, vector<vector<int>>(k, vector<int>(2)));

    int j = 0;

    function<int(int, int, int)> F = [&](int i, int t,
                                         int dir) -> int {
        if (dp[i][t][dir] != -1) return dp[i][t][dir];

        if (visj[i][t][dir] == j) return 0;
        visj[i][t][dir] = j;

        int result = 0;
        int ndir = d[i] == t ? !dir : dir;

        auto left = [&]() -> int {
            return F(i - 1, (t + (p[i] - p[i - 1])) % k,
                     ndir);
        };
        auto right = [&]() -> int {
            return F(i + 1, (t + (p[i + 1] - p[i])) % k,
                     ndir);
        };

        if (i == 0) {
            if (ndir) {
                result = right();
            } else {
                result = 1;
            }
        } else if (i == n - 1) {
            if (!ndir) {
                result = left();

            } else {
                result = 1;
            }
        } else {
            if (ndir) {
                result = right();
            } else {
                result = left();
            }
        }

        return dp[i][t][dir] = result;
    };

    int q;
    cin >> q;
    while (q--) {
        j++;
        int a;
        cin >> a;
        if (n == 1) {
            cout << "YES\n";
        } else {
            int i = lower_bound(p.begin(), p.end(), a) -
                    p.begin();
            if (i >= n || a < p[0]) {
                cout << "YES\n";
                continue;
            }
            int dist = p[i] - a;
            cout << (F(i, dist % k, 1) ? "YES\n" : "NO\n");
        }
    }
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
