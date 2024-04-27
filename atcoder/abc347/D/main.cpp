#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

#define cases 0
void solve() {
    ll a, b, C;
    cin >> a >> b >> C;
    ll cpc = __popcount(C), cnpc = 60 - cpc;
    int d = a + b - cpc;
    if (d >= 0 && d % 2 == 0) {
        ll X = 0, Y = 0;
        for (ll i = 0; i < 60; i++) {
            if (!a || !b) break;
            if ((C >> i) & 1) {
                cpc--;
                if (a < b) {
                    b--;
                    Y |= 1ULL << i;
                } else {
                    a--;
                    X |= 1ULL << i;
                }
            } else {
                if (cnpc > 0) {
                    cnpc--;
                    a--;
                    b--;
                    X |= 1ULL << i;
                    Y |= 1ULL << i;
                } else {
                    cnpc--;
                }
            }
        }
        cout << bitset<16>(X) << " " << bitset<16>(Y) << "\n";
        cout << X << " " << Y << "\n";
    } else {
        cout << "-1\n";
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
