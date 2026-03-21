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
        vector<int> vis(w * h);
        vector<double> dp(w * h);
        function<double(int)> solve = [&](int i) {
            cout << i << endl;
            sleep(1);
            if (i + 1 == w * h) return 0.;
            if (vis[i]) return dp[i];
            double result = 0;
            int same = 0;
            for (int j = 1; j <= 6; j++) {
                int k = i + j;
                if (k >= w * h) {
                    cout << k << " ";
                    k = w * h - (i - w * h + 2);
                    cout << k << endl;
                }
                if (i == k) {
                    same++;
                } else {
                    result += solve(k);
                }
            }
            vis[i] = 1;
            return dp[i] = result / (6. - same) + 1;
        };
        cout << solve(0) << "\n";
    }
}
