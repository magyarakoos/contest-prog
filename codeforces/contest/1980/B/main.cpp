#include <bits/stdc++.h>
#ifdef LOCAL
#include <magyarakoos-debug.h>
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

#define cases 1
void solve() {
    int N, F, K;
    cin >> N >> F >> K;
    vector<int> v(N);
    for (int& x : v) cin >> x;
    int val = v[F - 1];
    sort(rall(v));
    auto itl = lower_bound(all(v), val, greater<int>()) - v.begin();
    auto itr = upper_bound(all(v), val, greater<int>()) - v.begin() - 1;
    K--;
    if (K < itl) {
        cout << "NO\n";
        return;
    }
    if (K >= itr) {
        cout << "YES\n";
        return;
    }
    cout << "MAYBE\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}