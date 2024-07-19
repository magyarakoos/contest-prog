#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    vector g(N, vector<ll>(N)), dp(N, vector<ll>(1 << N));

    while (M--) {
        int U, V;
        cin >> U >> V;
        g[U - 1][V - 1]++;
    }

    dp[N - 1][1 << (N - 1)] = 1;

    for (int mask = 1 << (N - 1); mask < 1 << N; mask++) {
        for (int u = 0; u < N; u++) {
            if (!(mask >> u & 1)) continue;
            for (int v = 0; v < N; v++) {
                if (!(mask >> v & 1)) continue;
                dp[u][mask] += dp[v][mask ^ (1 << u)] * g[u][v];
                dp[u][mask] %= MOD;
            }
        }
    }

    cout << dp[0][(1 << N) - 1];
}
