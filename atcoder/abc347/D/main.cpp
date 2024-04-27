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
    ll cpc = __popcount(C);
    ll d = a + b - cpc;
    if (d >= 0 && d % 2 == 0) {
        ll X = 0, Y = 0;
        for (int i = 0; i < 60; i++) {
            bool curr = (C >> i) & 1;
            if (curr) {
                cpc--;
                if (a < b) {
                    b--;
                    Y |= curr << i;
                } else {
                    a--;
                    
                }
            } else {

            }
        }
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
