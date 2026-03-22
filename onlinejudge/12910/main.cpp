#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int w, h, s;
    while (cin >> w >> h >> s) {
        int n = w * h;
        vector<int> p(n), np(n);
        iota(p.begin(), p.end(), 0);
        while (s--) {
            int u, v;
            cin >> u >> v;
            p[u - 1] = v - 1;
        }
        for (int i = 0; i < n; i++) {
            int j = p[i];
            while (j != i) { j = p[j]; }
        }
        for (int i = 0; i < n; i++) { cout << p[i] << " "; }
        cout << "\n";
    }
}
