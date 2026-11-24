#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (string& s : a) cin >> s;
    for (int i = 0; i < n; i++) {
        if (count(a[i].begin(), a[i].end(), 'o') == 0) {
            cout << "Faucet " << i + 1 << "\n";
            return 0;
        }
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            cnt += a[j][i] == 'o';
        }
        if (!cnt) {
            cout << "Drain " << i + 1 << "\n";
            return 0;
        }
    }
}
