#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> ca(n + 1), cb(n + 1);
    for (int i = 1; i <= n; i++) {
        ca[i] = ca[i - 1];
        cb[i] = cb[i - 1];
        char c;
        cin >> c;
        if (c == 'a') {
            ca[i]++;
        } else {
            cb[i]++;
        }
    }
    auto bina = [&](int i) {
        int l = i - 1, r = n + 1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (ca[m] - ca[i - 1] >= a) {
                r = m;
            } else {
                l = m;
            }
        }
        return r;
    };
    auto binb = [&](int i) {
        int l = i - 1, r = n + 1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (cb[m] - cb[i - 1] >= b) {
                r = m;
            } else {
                l = m;
            }
        }
        return l;
    };
    int result = 0;
    for (int l = 1; l <= n; l++) {
        int i = bina(l), j = binb(l);
        result += max((int)0, j - i + 1);
    }
    cout << result << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
