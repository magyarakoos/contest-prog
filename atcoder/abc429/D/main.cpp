#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    int n, m, c;
    cin >> n >> m >> c;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int ai;
        cin >> ai;
        mp[ai]++;
    }
    vector<int> pos, cnt;
    for (auto [k, v] : mp) {
        pos.push_back(k);
        cnt.push_back(v);
    }
    if (pos.back() != m - 1) {
        pos.push_back(m - 1);
        cnt.push_back(0);
    }
    int k = pos.size();
    for (int i = 0; i < k; i++) cnt.push_back(cnt[i]);

    int r = 0;
    int cur_sum = 0;
    int result = 0;
    for (int l = 0; l < k; l++) {
        int mul = l ? pos[l] - pos[l - 1] : pos[l] + 1;

        while (cur_sum < c) {
            assert(r < 2 * k);
            cur_sum += cnt[r];
            r++;
        }
        result += mul * cur_sum;

        cur_sum -= cnt[l];
    }
    cout << result << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
