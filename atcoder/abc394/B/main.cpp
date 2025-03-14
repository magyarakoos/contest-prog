#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    int N;
    cin >> N;
    vector<string> a(N);
    for (auto& s : a) cin >> s;
    sort(a.begin(), a.end(), [](auto s, auto t) {
        return s.size() < t.size();
    });
    for (auto s : a) cout << s;
    cout << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
