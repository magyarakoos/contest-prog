#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int w, h, s;
    while (cin >> w >> h >> s) {
        vector<int> p(w * h);
        iota(p.begin(), p.end(), 0);
        while (s--) {
            int u, v;
            cin >> u >> v;
            p[u - 1] = v - 1;
        }
        vector<bool> vis(w * h);
        vector<double> dp(w * h);
        function<double(int)> solve = [&](int i) {
            if (i + 1 == w * h) return 0.;
            if (i >= w * h) return solve(2 * w * h - i - 2);
            if (vis[i]) return dp[i];
            int result = 0;
            for (int j = 1; j <= 6; j++) {
                result += solve(i + j);
            }
            return dp[i] = result / 6;
        };
    }
}
