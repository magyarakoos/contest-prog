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

#define cases 1
void solve() {
    int N, M;
    cin >> N >> M;
    vector<string> m(N);
    for (string& s : m) {
        cin >> s;
    }
    int mx_row = -1, mx_val = 0;
    for (int i = 0; i < N; i++) {
        int cnt = count(all(m[i]), '#');
        if (mx_val < cnt) {
            mx_val = cnt;
            mx_row = i;
        }
    }
    int start_j = 0;
    for (int j = 0; j < M; j++) {
        if (m[mx_row][j] == '#') {
            start_j = j;
            break;
        }
    }
    int end_j = M - 1;
    for (int j = M - 1; ~j; j--) {
        if (m[mx_row][j] == '#') {
            end_j = j;
            break;
        }
    }
    DB(start_j, end_j);
    cout << mx_row + 1 << " ";
    cout << (start_j + end_j) / 2 + 1 << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
