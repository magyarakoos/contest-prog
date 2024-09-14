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

const ll INF = 2e9, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    int N;
    cin >> N;
    vector a(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) { cin >> a[i][j]; }
    }
    DB(a);
    int x = 1;
    for (int i = 1; i <= N; i++) {
        int y = i;
        if (x < y) swap(x, y);
        x = a[x - 1][y - 1];
    }
    cout << x;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
