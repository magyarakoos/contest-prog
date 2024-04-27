#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

#define cases 0
void solve() {
    int a = 0, b = 0;
    for (int i = 0; i < 9; i++) {
        int x;
        cin >> x;
        a += x;
    }
    for (int i = 0; i < 8; i++) {
        int x;
        cin >> x;
        b += x;
    }
    cout << a - b + 1;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
