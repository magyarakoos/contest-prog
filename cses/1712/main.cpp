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

void solve() {
    ll A, B, C;
    cin >> A >> B >> C;
    cout << mpow(A, mpow(B, C)) << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}