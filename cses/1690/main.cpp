#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

void madd(int& x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> g(N);

    while (M--) {
        int U, V;
        cin >> U >> V;
        g[V - 1].push_back(U - 1);
    }

    vector dp(1 << N, vector<int>(N));

    dp[1][0] = 1;

    for (int mask = 1; mask < 1 << N; mask++) {
        for (int u = 0; u < N - 1; u++) {
            if (!(mask >> u & 1)) continue;
            for (int v : g[u]) {
                if (!(mask >> v & 1)) continue;
                madd(dp[mask][u], dp[mask ^ (1 << u)][v]);
            }
        }
    }

    cout << dp[(1 << N) - 1][N - 1];
}
