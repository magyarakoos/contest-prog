#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

#define cases 1
void solve() {
    int N, M;
    cin >> N >> M;
    vector<string> v(N, string(M, ' '));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> v[i][j];
        }
    }
    bool brow = 0, wrow = 0;
    if (!count(all(v[0]), 'B') || !count(all(v[N - 1]), 'B')) {
        wrow = 1;
    }
    if (!count(all(v[0]), 'W') || !count(all(v[N - 1]), 'W')) {
        brow = 1;
    }
    int bc1 = 0, wc1 = 0, bc2 = 0, wc2 = 0;
    for (int i = 0; i < N; i++) {
        bc1 += v[i][0] == 'B';
        bc2 += v[i][M - 1] == 'B';
        wc1 += v[i][0] == 'W';
        wc2 += v[i][M - 1] == 'W';
    }
    if (!wc1 || !wc2) {
        brow = 1;
    }
    if (!bc1 || !bc2) {
        wrow = 1;
    }
    cout << (brow && wrow ? "NO\n" : "YES\n");
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
