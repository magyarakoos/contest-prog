#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<bool> a(n + 1);
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        a[i + 1] = c == 'K';
    }
    vector<int> ps(n + 1), ss(n + 2);
    for (int i = 1; i <= n; i++) {
        ps[i] = ps[i - 1] + !a[i];
    }
    for (int i = n; i > 0; i--) {
        ss[i] = ss[i + 1] + a[i];
    }
    int result = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i]) continue;
        int ac = ps[i];
        int kc = ss[i + 1];
        result = max(result, min(ac, kc));
    }
    cout << result * 2 << "\n";
}
