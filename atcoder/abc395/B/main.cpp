#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    int N;
    cin >> N;
    vector<string> a(N, string(N, '#'));
    for (int i = 1; i * 2 < N; i += 2) {
        for (int j = 0; j < N - i * 2; j++) {
            a[i][j + i] = '.';
            a[N - i - 1][j + i] = '.';
            a[j + i][i] = '.';
            a[j + i][N - i - 1] = '.';
        }
    }
    for (string s : a) cout << s << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
