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

#define cases 0
void solve() {
    int H, W, N;
    cin >> H >> W >> N;
    vector<array<int, 2>> a(N), b(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i][0] >> a[i][1];
        b[i] = {a[i][1], a[i][0]};
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
