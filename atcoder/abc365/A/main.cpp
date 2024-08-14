#include <bits/stdc++.h>
#ifdef LOCAL
#include <debug.h>
#else
#define DB(...)
#endif

using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) (int)v.size()

const ll INF = 2e9, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    int Y;
    cin >> Y;
    if (Y % 400 == 0) {
        cout << "366\n";
    } else if (Y % 100 == 0) {
        cout << "365\n";
    } else if (Y % 4 == 0) {
        cout << "366\n";
    } else {
        cout << "365\n";
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
