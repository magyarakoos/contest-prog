#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    vector<vector<int>> res;
    vector<int> res_w;
    for (int k = 1; k < n; k++) {
        if (n % k) continue;
        int nk = n / k;
        int w = 0;
        for (int i = nk - 1; i < n; i += nk) {
            int j = i - nk + 1;
            w = max(w, a[i] - a[j]);
        }
        bool ok = 1;
        vector<int> cur;
        int tip = a[nk - 1] - w;
        cur.push_back(tip);
        tip += w;
        for (int i = 2 * nk - 1; i < n; i += nk) {
            int j = i - nk + 1;
            if (tip >= a[j]) {
                ok = 0;
                break;
            }
            tip = max(tip + 1, a[i] - w);
            cur.push_back(tip);
            tip += w;
        }
        if (!ok) continue;
        res_w.push_back(w);
        res.push_back(cur);
    }

    cout << res.size() << "\n";
    for (int i = 0; i < (int)res.size(); i++) {
        cout << res[i].size() << " " << res_w[i] << "\n";
        for (int x : res[i]) cout << x << "\n";
    }
}
