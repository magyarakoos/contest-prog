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
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

const ll INF = 2e9, MAXN = 2e5, MOD = 1e9 + 7;

int rcnt(const vector<int>& a, int l, int r) {
    auto itl = lower_bound(all(a), l);
    auto itr = upper_bound(all(a), r);
    return itr - itl;
}

#define cases 0
void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> a(N);
    for (int& x : a) cin >> x;
    sort(all(a));

    while (Q--) {
        int b, k;
        cin >> b >> k;

        int l = -1, r = 1e9;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (rcnt(a, b - m, b + m) >= k) {
                r = m;
            } else {
                l = m;
            }
        }

        cout << r << "\n";
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
