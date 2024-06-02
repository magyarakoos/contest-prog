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
    int N, M, K;
    cin >> N >> M >> K;
    vector<bool> R(M);
    vector<vector<int>> v(M);
    for (int i = 0; i < M; i++) {
        int cnt;
        cin >> cnt;
        while (cnt--) {
            int X;
            cin >> X;
            v[i].push_back(X);
        }
        char c;
        cin >> c;
        R[i] = c == 'o';
    }
    int res = 0;
    for (int mask = 0; mask < (1 << N); mask++) {
        bool ok = 1;
        for (int i = 0; i < M; i++) { 
            int opcnt = 0;
            for (int x : v[i]) {
                opcnt += mask >> (x - 1) & 1;
            }
            if ((opcnt >= K && !R[i]) || (opcnt < K && R[i])) {
                ok = 0;
                break;
            }
        }
        res += ok;
    }
    cout << res;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}