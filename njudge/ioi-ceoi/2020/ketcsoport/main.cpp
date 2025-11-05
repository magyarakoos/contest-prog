#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<bool> g(n + 1);
    for (int i = 1; i <= n; i++) {
        vector<int> e;
        int x;
        while ((cin >> x) && x) e.push_back(x);
        if (e.size() <= 2) {
            g[i] = !g[e[0]];
        } else {
            int zcnt = 0, ocnt = 0;
            for (int j = 0; j < 3; j++) {
                (g[e[j]] ? ocnt : zcnt)++;
            }
            g[i] = (zcnt > ocnt);
        }
    }
}
