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
            p[u] = v;
        }
        vector<bool> vis(w * h);
        vector<double> dp(w * h);
        function<void(int)> solve = [&](int i) {

        };
    }
}
