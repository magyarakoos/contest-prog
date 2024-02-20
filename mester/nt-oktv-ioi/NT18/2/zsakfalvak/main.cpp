#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

vector<vector<int>> g;
vector<bool> vis;

void dfs(int u) {
    
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    g.resize(N + 1);

    while (M--) {
        int U, V;
        cin >> U >> V;

        g[U].push_back(V);
        g[V].push_back(U);
    }

    vis.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        if (!vis[i] && size(g[i]) == 1) {
            dfs(i);
        }
    }
}