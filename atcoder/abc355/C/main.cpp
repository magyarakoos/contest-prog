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

#define cases 0
void solve() {
    int N, T;
    cin >> N >> T;
    vector<int> rowS(N), colS(N);
    int diag1 = 0, diag2 = 0;
    for (int tc = 1; tc <= T; tc++) {
        int X;
        cin >> X;
        X--;
        int i = X / N, j = X % N;
        rowS[i]++;
        colS[j]++;
        if (i == j) diag1++;
        if (i == N - j - 1) diag2++;
        if (rowS[i] == N || colS[j] == N || diag1 == N || diag2 == N) {
            cout << tc;
            return;
        }
    }
    cout << -1;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}