#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 1
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    vector<int> cnt(n + 1);
    for (int x : a) cnt[x]++;
    int can_del = 0;
    vector<int> arr;
    for (int i = 0; i <= n; i++) {
        if (cnt[i]) arr.push_back(i);
        can_del += max<int>(0, cnt[i] - 1);
    }
    while (can_del < n - k + 1) {
        arr.pop_back();
        can_del++;
    }
    set<int> s;
    for (int x : arr) s.insert(x);
    for (int i = 0; i <= n; i++) {
        if (!s.count(i)) {
            cout << i << "\n";
            return;
        }
    }
    assert(0);
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
