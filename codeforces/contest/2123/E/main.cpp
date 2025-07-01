#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 1
void solve() {
    int n;
    cin >> n;
    vector<int> cnt(n + 2);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    vector<int> ranges(2 * n + 5);
    for (int i = 0; i <= n; i++) {
        if (!cnt[i]) break;
        ranges[cnt[i]]++;
        ranges[n - i]--;
    }
    for (int i = 1; i <= n; i++) ranges[i] += ranges[i - 1];
    for (int i = 0; i <= n; i++) {
        cout << ranges[i] + 1 << " ";
    }
    cout << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
