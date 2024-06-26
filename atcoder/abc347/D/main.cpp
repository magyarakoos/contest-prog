#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

#define cases 0
void solve() {
    int a, b;
    ll C, X = 0, Y = 0;
    cin >> a >> b >> C;
    for (int i = 0; i < 60; i++) {
        if ((C >> i) & 1) {
            if (b < a) {
                a--;
                X |= 1ULL << i;
            } else {
                b--;
                Y |= 1ULL << i;
            }
        }
    }
    for (int i = 0; i < 60; i++) {
        if (!((C >> i) & 1) && a > 0 && b > 0) {
            a--;
            b--;
            X |= 1ULL << i;
            Y |= 1ULL << i;
        }
    }
    if (!a && !b) cout << X << " " << Y;
    else cout << -1;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
