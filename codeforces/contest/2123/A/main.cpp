#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 1
void solve() {
    int n;
    cin >> n;
    vector<int> cnt(4);
    for (int i = 0; i < n; i++) cnt[i % 4]++;
    int a = abs(cnt[0] - cnt[3]), b = abs(cnt[1] - cnt[2]);
    cout << (a + b ? "Alice\n" : "Bob\n");
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
