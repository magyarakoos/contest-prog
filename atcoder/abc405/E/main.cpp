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

int fact[MAXN];

int choose(int n, int k) {
    return fact[n] * inv(fact[k]) * inv(fact[n - k]) % MOD;
}

int32_t main() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    cin.tie(0), ios::sync_with_stdio(0);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << inv(3);
    vector<int> ab(b + 1), cd(c + 1);
    for (int i = 0; i <= b; i++) {
        ab[i] = choose(a + i, i);
    }
    for (int i = 0; i <= c; i++) {
        cd[i] = choose(d + i, i);
    }

    /*
     * A -> C
     * A -> D
     * B -> D
     *
     * AB -> BC -> CD
     */
}
