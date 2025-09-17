#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> a(n + 1), pre(n + 1), suf(n + 2, 1e9);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        pre[i] = max(pre[i - 1], a[i]);
    }
    for (int i = n; i > 0; i--) {
        suf[i] = min(suf[i + 1], a[i]);
    }
    vector<int> result;
    for (int i = 1; i <= n; i++) {
        if (pre[i - 1] < a[i] && suf[i + 1] > a[i]) {
            result.push_back(a[i]);
        }
    }
    cout << result.size();
    for (int x : result) cout << " " << x;
    cout << "\n";
}
