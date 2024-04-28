#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

int calc(const vector<bool>& v) {
    vector<int> dp(sz(v));
    int res = 0;
    for (int i = 0; i < sz(v); i++) {
        if (i) {
            smax(res, (dp[i] = (dp[i - 1] + 1) * v[i]));
        } else {
            smax(res, (dp[i] = v[i]));
        }
    }
    return res;
}

#define cases 0
void solve() {
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<vector<bool>> m(N, vector<bool>(M));
    vector<int> mxS(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c;
            cin >> c;
            m[i][j] = c == '1';
        }
        mxS[i] = calc(m[i]);
    }

    while (Q--) {
        int i, j;
        cin >> i >> j;
        i--; j--;
        m[i][j] = !m[i][j];
        mxS[i] = calc(m[i]);
        cout << *max_element(all(mxS)) << "\n";
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
