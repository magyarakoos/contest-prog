// O(log(C) + log(B^C))
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

void mmul(ll& x, ll y) {
    x = (x % MOD) * (y % MOD) % MOD;
}

void mpow(ll& x, ll y) {
    ll res = 1;
    x %= MOD;
    while (y > 0) {
        if (y & 1) {
            mmul(res, x);
        }
        mmul(x, x);
        y >>= 1;
    }
    x = res;
}

void solve() {
    ll A, B, C;
    cin >> A >> B >> C;
    mpow(B, C);
    mpow(A, B);
    cout << A << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}