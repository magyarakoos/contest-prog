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

const ll INF = 2e9, MAXN = 2e5, MOD = 998244353;

tuple<int, int, vector<vector<array<int, 2>>>> preproc() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<int> spV = {1};
    vector<array<int, 2>> edgeS(M);
    for (auto& [U, V] : edgeS) {
        cin >> U >> V;
        spV.push_back(U);
        spV.push_back(V);
    }
    sort(all(spV));
    spV.erase(unique(all(spV)), spV.end());
    int NN = sz(spV);

    map<int, int> to;
    for (int i = 0; i < NN; i++) to[spV[i]] = i + 1;

    vector<vector<array<int, 2>>> g(NN + 1);

    for (auto [U, V] : edgeS) g[to[U]].push_back({to[V], 1});
    for (int i = 1; i < NN; i++) {
        g[to[spV[i - 1]]].push_back({to[spV[i]], spV[i] - spV[i - 1]});
    }
    g[to[spV[NN - 1]]].push_back({1, N - spV[NN - 1] + 1});

    return {NN, K, g};
}

#define cases 0
void solve() {
    auto [N, K, g] = preproc();
    vector<vector<int>> dp(N + 1, vector<int>(K + 1));

    function<int(int, int)> dfs = [&](int u, int k) {
        if (k <= 0) return 1;
        if (dp[u][k]) return dp[u][k];
        for (auto [v, w] : g[u]) {
            dp[u][k] = (dp[u][k] + dfs(v, k - w)) % MOD;
        }
        return dp[u][k];
    };

    cout << dfs(1, K);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
