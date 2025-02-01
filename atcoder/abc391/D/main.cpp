#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    int N, W;
    cin >> N >> W;
    vector<vector<int>> yS(W);
    vector<int> m(N);
    for (int i = 0; i < N; i++) {
        int X, Y;
        cin >> X >> Y;
        X--, Y--;
        m[i] = yS[X].size();
        yS[X].push_back(Y);
    }

    int M = N;
    for (int i = 0; i < W; i++)
        M = min(M, (int)yS[i].size());

    vector<int> t(M);
    if (M > 0) {
        for (int i = 0; i < W; i++) {
            t[0] = max(t[0], yS[i][0] + 1);
        }
        for (int i = 1; i < M; i++) {
            for (int j = 0; j < W; j++) {
                if (i < yS[j].size()) {
                    t[i] = max(t[i], max(t[i - 1] + 1,
                                         yS[j][i] + 1));
                }
            }
        }
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int Ti, Ai;
        cin >> Ti >> Ai;
        int pos = m[Ai - 1];
        if (pos >= M || t[pos] > Ti) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
