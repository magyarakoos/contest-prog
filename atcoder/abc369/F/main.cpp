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

const ll INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

bool cmp(array<int, 2> a, array<int, 2> b) { // a < b
    return a[0] <= b[0] && a[1] <= b[1];
}

#define cases 0
void solve() {
    int H, W, N;
    cin >> H >> W >> N;

    vector<array<int, 2>> a(N);
    for (auto& [i, j] : a) cin >> i >> j;

    sort(all(a));

    vector<array<int, 2>> lis;

    for (auto p : a) {
        auto it = lower_bound(all(lis), p, cmp);
        if (it == lis.end()) {
            lis.push_back(p);
        } else {
            lis[it - lis.begin()] = p;
        }
    }

    DB(lis)

    cout << sz(lis);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
