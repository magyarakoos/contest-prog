#include <bits/stdc++.h>

#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

vector<vector<int>> g;
vector<int> distS;
vector<bool> vis, is_boss;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;

    g.resize(N + 1);
    vis.resize(N + 1);
    distS.resize(N + 1);
    is_boss.assign(N + 1, 1);

    for (int U = 1; U <= N; U++) {
        int V;
        cin >> V;
        if (V != -1) {
            g[V].push_back(U);
            is_boss[U] = 0;
        }
    }

    queue<array<int, 2>> q;

    for (int i = 1; i <= N; i++) {
        if (is_boss[i]) {
            q.push({i, 1});
            vis[i] = 1;
        }
    }

    int result = 0;

    while (!q.empty()) {
        auto [node, level] = q.front();
        q.pop();

        result = max(result, level);

        for (int neigh : g[node]) {
            if (!vis[neigh]) {
                vis[neigh] = 1;
                q.push({neigh, level + 1});
            }
        }
    }

    cout << result;
}
