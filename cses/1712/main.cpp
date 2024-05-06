#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

ll mmul(ll a, ll b) {
    return (a * b) % MOD;
}

ll mpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res = mmul(res, a);
        }
        a = mmul(a, a);
        b >>= 1;
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        ll A, B, C;
        cin >> A >> B >> C;
        cout << mpow(A, mpow(B, C)) << "\n";
    }
}
