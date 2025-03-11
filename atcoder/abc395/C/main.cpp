#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 1e6, MOD = 1e9 + 7;

#define cases 0
void solve() {
    int N;
    cin >> N;
    vector<vector<int>> h(MAXN);
    for (int i = 0, x; i < N; i++) {
        cin >> x;
        h[x - 1].push_back(i);
    }
    int result = N + 1;
    for (int i = 0; i < MAXN; i++) {
        for (int j = 1; j < h[i].size(); j++) {
            result = min(result, h[i][j] - h[i][j - 1] + 1);
        }
    }
    cout << (result <= N ? result : -1) << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
