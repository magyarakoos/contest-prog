#include <iostream>

using namespace std;
using ll = long long;

ll sum(ll a, ll b) { return b * (b + 1) / 2 - a * (a - 1) / 2; }

void solve() {
    ll N, K;
    cin >> N >> K;

    ll l = N, r = N + K - 1;
    while (r - l > 1) {
        ll m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
        ll f1 = 0;
        ll f2 = 0;
        if (f1 < f2) {
            l = m1;
        } else {
            r = m2;
        }
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}
