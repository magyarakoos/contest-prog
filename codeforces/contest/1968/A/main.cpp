#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

#define cases 1
void solve() {
    int X;
    cin >> X;
    int mx = -1, mxy = 0;
    for (int Y = 1; Y < X; Y++) {
        if (gcd(X, Y) + Y > mx) {
            mx = gcd(X, Y) + Y;
            mxy = Y;
        }
    }
    cout << mxy << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
