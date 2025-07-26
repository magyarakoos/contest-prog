#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    int n;
    cin >> n;

    vector fw(n + 2, vector<int>(n + 2, INF));

    for (int i = 1; i <= n + 1; i++) fw[i][i] = 0;

    {
        int m;
        cin >> m;
        while (m--) {
            int u, v, w;
            cin >> u >> v >> w;
            fw[u][v] = min(fw[u][v], w);
            fw[v][u] = min(fw[v][u], w);
        }
    }

    int t;
    {
        int k;
        cin >> k >> t;
        while (k--) {
            int u;
            cin >> u;
            fw[u][n + 1] = t;
            fw[n + 1][u] = 0;
        }
    }

    for (int k = 1; k <= n + 1; k++) {
        for (int i = 1; i <= n + 1; i++) {
            for (int j = 1; j <= n + 1; j++) {
                fw[i][j] =
                    min(fw[i][j], fw[i][k] + fw[k][j]);
            }
        }
    }

    {
        int q;
        cin >> q;
        while (q--) {
            int type;
            cin >> type;
            if (type == 1) {
                int u, v, w;
                cin >> u >> v >> w;
                fw[u][v] = min(fw[u][v], w);
                fw[v][u] = min(fw[v][u], w);
                for (int i = 1; i <= n + 1; i++) {
                    for (int j = 1; j <= n + 1; j++) {
                        fw[i][j] =
                            min({fw[i][j],
                                 fw[i][u] + fw[v][j] + w,
                                 fw[i][v] + fw[u][j] + w});
                    }
                }
            } else if (type == 2) {
                int u;
                cin >> u;
                fw[u][n + 1] = t;
                fw[n + 1][u] = 0;
                for (int i = 1; i <= n + 1; i++) {
                    for (int j = 1; j <= n + 1; j++) {
                        fw[i][j] = min(
                            {fw[i][j],
                             fw[i][u] + fw[n + 1][j] + t,
                             fw[i][n + 1] + fw[u][j]});
                    }
                }
            } else {
                int sum = 0;
                for (int u = 1; u <= n; u++) {
                    for (int v = 1; v <= n; v++) {
                        if (fw[u][v] < INF) {
                            sum += fw[u][v];
                        }
                    }
                }
                cout << sum << "\n";
            }
        }
    }
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
