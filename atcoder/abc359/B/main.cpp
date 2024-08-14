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
    map<int, vector<int>> m;
    for (int i = 0; i < N * 2; i++) {
        int x;
        cin >> x;
        m[x].push_back(i);
    }
    int x = 0;
    for (int i = 1; i <= N; i++) {
        x += abs(m[i][0] - m[i][1]) == 2;
    }
    cout << x << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
