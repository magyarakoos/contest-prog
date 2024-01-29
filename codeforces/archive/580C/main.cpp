#include <bits/stdc++.h>

#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<bool> has_cat(N + 1);
    for (int i = 1; i <= N; i++) {
        char b;
        cin >> b;
        has_cat[i] = b == '1';
    }

    vector<vector<int>> g(N + 1);

    for (int i = 1; i < N; i++) {
        int U, V;
        cin >> U >> V;
        g[U].push_back(V);
        g[V].push_back(U);
    }

    vector<bool> vis(N + 1);
    queue<array<int, 2>> q({{1, has_cat[1]}});
    vis[1] = 1;
    
    int result = 0;

    while (!q.empty()) {
        auto [node, cats] = q.front();
        q.pop();

        if (cats > M) {
            continue;
        }

        if (node != 1 && size(g[node]) == 1) {
            result++;
            continue;
        }

        for (int neigh : g[node]) {
            if (!vis[neigh]) {
                vis[neigh] = 1;
                q.push({neigh, (has_cat[node] ? cats + has_cat[neigh] : has_cat[neigh])});
            }
        }
    }

    cout << result;
}