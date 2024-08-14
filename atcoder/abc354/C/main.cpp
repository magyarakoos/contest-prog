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

#define cases 0
void solve() {
    int N;
    cin >> N;
    vector<array<int, 3>> v(N);
    for (auto& [A, C, i] : v) cin >> A >> C;
    for (int i = 0; i < N; i++) v[i][2] = i;
    sort(all(v));
    vector<int> res;
    int mn_cost = INF;
    for (int i = N - 1; i >= 0; i--) {
        if (v[i][1] < mn_cost) {
            mn_cost = v[i][1];
            res.push_back(v[i][2]);
        }
    }
    sort(all(res));
    cout << sz(res) << "\n";
    for (int x : res) cout << x + 1 << " ";
    cout << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
