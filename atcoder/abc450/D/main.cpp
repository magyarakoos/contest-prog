#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int& x : a) {
        cin >> x;
        x %= k;
    }
    sort(a.begin(), a.end());
    deque<int> b;
    for (int x : a) b.push_back(x);
    int result = INF;
    for (int i = 0; i <= n; i++) {
        result = min(result, b.back() - b.front());
        b.push_back(b.front() + k);
        b.pop_front();
    }
    cout << result << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
