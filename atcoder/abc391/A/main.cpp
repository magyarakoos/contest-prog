#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    string S;
    cin >> S;
    if (S == "N") {
        cout << "S\n";
    } else if (S == "E") {
        cout << "W\n";
    } else if (S == "S") {
        cout << "N\n";
    } else if (S == "W") {
        cout << "E\n";
    } else if (S == "NE") {
        cout << "SW\n";
    } else if (S == "NW") {
        cout << "SE\n";
    } else if (S == "SE") {
        cout << "NW\n";
    } else {
        cout << "NE\n";
    }
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
