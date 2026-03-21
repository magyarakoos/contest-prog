#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    string nl;
    while (1) {
        int w, h, s;
        if (!(cin >> w >> h >> s)) break;
        vector<int> p(w * h);
        iota(p.begin(), p.end(), 0);
        while (s--) {
            int u, v;
            cin >> u >> v;
            p[u] = v;
            cout << u << " " << v << endl;
        }
    }
}
