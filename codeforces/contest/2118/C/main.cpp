#include <bit>
#include <bits/stdc++.h>
using namespace std;
#define int uint64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 1
void solve() {
    int n, k, result = 0;
    cin >> n >> k;
    vector<int> a(n);
    for (int& x : a) {
        cin >> x;
        result += popcount(x);
    }
    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < n; j++) {
            if (!(a[j] >> i & 1)) {
                if (k >= ((int)1 << i)) {
                    k -= ((int)1 << i);
                    result++;
                    a[j] |= ((int)1 << i);
                }
            }
        }
    }
    cout << result << "\n";
    
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
