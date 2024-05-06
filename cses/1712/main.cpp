#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void mmul(ll a, ll b, ll m) {
    a = a * b % m;
}

ll mpow(ll a, ll b, ll m) {
    ll res = 1;
    a %= m;
    while (b > 0) {
        if (b & 1) {
            mmul(res, a, m);
        }
        mmul(a, a, m);
        b >>= 1;
    }
    return res;
}

int main() {
    const ll MOD = 1e9 + 7;
    int T;
    cin >> T;
    while (T--) {
        ll A, B, C;
        cin >> A >> B >> C;
        cout << mpow(A, mpow(B, C, MOD - 1), MOD) << "\n";
    }
}
