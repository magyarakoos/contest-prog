#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    vector<string> o = {"Ocelot", "Serval", "Lynx"};
    string s, t;
    cin >> s >> t;
    int i = find(o.begin(), o.end(), s) - o.begin(),
        j = find(o.begin(), o.end(), t) - o.begin();
    cout << (i >= j ? "Yes" : "No") << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
