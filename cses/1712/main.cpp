#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) (int)v.size()

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

void mmul(int& x, int y) {
    x = (ll) x * y % MOD;
}

int mpow(int x, int y) {
    int res = 1;
    while (y > 0) {
        cout << "AYE ";
        if (y % 1) {
            mmul(res, x);
        }
        mmul(x, x);
        y >>= 1;
    }
    cout << res << "\n";
    return res;
}

void solve() {
    int A, B, C;
    cin >> A >> B >> C;
    B = mpow(B, C);
    A = mpow(A, B);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}