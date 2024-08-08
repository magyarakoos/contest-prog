#include <bits/stdc++.h>
using namespace std;

int dfs(const vector<vector<int>>& g, map<vector<int>, int>& m, int u, int p) {
    vector<int> szS;
    for (int v : g[u]) {
        if (v == p) continue;
        szS.push_back(dfs(g, m, v, u));
    }
    sort(szS.begin(), szS.end());
    if (m.count(szS)) return m[szS];
    return m[szS] = m.size();
}

void solve() {
    int N;
    cin >> N;
    vector g(2, vector<vector<int>>(N + 1));
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j < N; j++) {
            int U, V;
            cin >> U >> V;
            g[i][U].push_back(V);
            g[i][V].push_back(U);
        }
    }
    map<vector<int>, int> ma;
    cout << (dfs(g[0], ma, 1, 0) == dfs(g[1], ma, 1, 0) ? "YES" : "NO") << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}
