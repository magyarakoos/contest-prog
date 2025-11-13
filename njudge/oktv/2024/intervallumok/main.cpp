#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    vector<int> push_i(n);
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
        int over = 0;
        for (int i = 2 * nk - 1; i < n - 1; i += nk) {
            int j = i - nk;
            if (a[i] - a[j] - over < w) {
                over = w - (a[i] - a[j] - over);
                push_i[i] = over;
                if (over > a[i + 1] - a[i]) {
                    ok = 0;
                    break;
                }
            }
        }
        if (!ok) { continue; }
        res_w.push_back(w);
        res.push_back({});
        for (int i = nk - 1; i < n; i += nk) {
            res.back().push_back(a[i] + push_i[i] - w);
        }
    }

    cout << res.size() << "\n";
    for (int i = 0; i < (int)res.size(); i++) {
        cout << res[i].size() << " " << res_w[i] << "\n";
        for (int x : res[i]) cout << x << "\n";
    }
}
