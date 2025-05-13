#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MOD = 998244353, MAXN = 1e6 + 1;

int inv(int a) {
    int res = 1, b = MOD - 2;
    while (b) {
        if (b & 1) {
            (a *= a) %= MOD;
            (res *= a) %= MOD;
        }
        b /= 2;
    }
    return res;
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<int> fact(MAXN, 1);
    for (int i = 1; i < MAXN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    cout << inv(3);
    /*
     * A -> C
     * A -> D
     * B -> D
     *
     * AB -> BC -> CD
     * a^(p - 1) = p^0 (p)
     * a^(p - 2) = p^(-1) (p)
     */
}
