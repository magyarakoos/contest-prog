#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    string nl;
    do {
        int w, h, s;
        cin >> w >> h >> s;
        vector<int> p(w * h);
        iota(p.begin(), p.end(), 0);
        while (s--) {
            int u, v;
            cin >> u >> v;
            p[u] = v;
            cout << u << " " << v << endl;
        }
    } while (getline(cin, nl) != "");
}
