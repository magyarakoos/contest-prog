// O(log(C) + log(B^C))
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

ll mmul(ll a, ll b) {
    return (a * b) % MOD;
}

ll mpow(ll a, ll b) {
    if (b == 0) return 1;
    ll res = mpow(a, b / 2);
    if (b % 2) {
        return mmul(mmul(res, res), a);
    } else {
        return mmul(res, res);
    }
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