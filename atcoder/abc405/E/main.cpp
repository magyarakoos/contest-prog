#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MOD = 998244353, MAXN = 1e6 + 1;

int inv(int a) {
    int res = 1, b = MOD - 2;
    while (b) {
        if (b & 1) (res *= a) %= MOD;
        (a *= a) %= MOD;
        b /= 2;
    }
    return res;
}

int32_t main() {
    vector<int> fact(MAXN, 1);
    for (int i = 1; i < MAXN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    cin.tie(0), ios::sync_with_stdio(0);

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << inv(3);
    /*
     * A -> C
     * A -> D
     * B -> D
     *
     */
}
