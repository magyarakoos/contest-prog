#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    string s;
    int a;
    cin >> s >> a;
    int h = (stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3)) +
             a) %
            (24 * 60);
    cout << setfill('0') << setw(2) << h / 60 << ":"
         << setw(2) << h % 60 << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
