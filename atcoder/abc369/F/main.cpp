#include <algorithm>
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

const ll INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    int N, M;
    cin >> N >> M;
    vector<array<ll, 3>> edgeS(M);
    for (auto& [u, v, w] : edgeS) cin >> u >> v >> w;

    vector FW(N + 1, vector<ll>(N + 1, INF));

    for (int u = 1; u <= N; u++) { FW[u][u] = 0; }

    for (auto [u, v, w] : edgeS) {
        FW[u][v] = min(FW[u][v], w);
        FW[v][u] = min(FW[v][u], w);
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (FW[i][k] < INF && FW[k][j] < INF) {
                    FW[i][j] = min(FW[i][j], FW[i][k] + FW[k][j]);
                }
            }
        }
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int K;
        cin >> K;
        vector<int> b(K);
        for (int& x : b) cin >> x;
        ll result = INF;
        do {
            for (int mask = 0; mask < (1 << K); mask++) {
                vector<int> order, noc;
                ll curr = 0;
                order.push_back(1);
                for (int i = 0; i < K; i++) {
                    if (mask >> i & 1) {
                        order.push_back(edgeS[b[i] - 1][0]);
                        order.push_back(edgeS[b[i] - 1][1]);
                    } else {
                        order.push_back(edgeS[b[i] - 1][1]);
                        order.push_back(edgeS[b[i] - 1][0]);
                    }
                    curr += edgeS[b[i] - 1][2];
                    noc.push_back(sz(order) - 1);
                }
                order.push_back(N);

                int noci = 0;
                for (int i = 1; i < sz(order); i++) {
                    if (noci < sz(noc) && noc[noci] == i) {
                        noci++;
                    } else {
                        curr += FW[order[i - 1]][order[i]];
                    }
                }
                result = min(result, curr);
            }
        } while (next_permutation(all(b)));
        cout << result << "\n";
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
