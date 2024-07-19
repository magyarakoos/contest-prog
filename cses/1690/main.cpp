#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll g[21][21], dp[21][1 << 20];
const ll MOD = 1e9 + 7;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    while (M--) {
        int U, V;
        cin >> U >> V;
        g[--U][--V]++;
    }

    dp[N - 1][1 << (N - 1)] = 1;

    for (int mask = 1 << (N - 1); mask < 1 << N; mask++) {
        for (int u = 0; u < N; u++) {
            if (!(mask >> u & 1)) continue;
            for (int v = 0; v < N; v++) {
                if (v == u) continue;
                if (mask & (1 << v)) {
                    dp[u][mask] += dp[v][mask - (1 << u)] * g[u][v];
                    dp[u][mask] %= MOD;
                }
            }
        }
    }
    cout << dp[0][(1 << N) - 1];
}
