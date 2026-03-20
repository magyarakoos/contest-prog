#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MOD = 1e9 + 7, BMOD = 10;

int mpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b % 2) {
            res *= a;
            res %= MOD;
        }
        a *= a;
        a %= MOD;
        b /= 2;
    }
    return res;
}

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    set<int> hS;
    int h = 0;
    for (int i = 0; i < n; i++) {
        h *= BMOD;
        h %= MOD;
        if (i - k >= 0) {
            h += MOD - mpow(BMOD, k) * (s[i - k] - 'a' + 1);
            h %= MOD;
        }
        h += s[i] - 'a' + 1;
        h %= MOD;
        if (i >= k - 1) hS.insert(h);
    }
    cout << hS.size() << "\n";
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) solve();
}
