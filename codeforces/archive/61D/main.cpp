#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()

int main() {
	cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<vector<array<int, 2>>> g(N + 1);

    ll result = 0;
    
    for (int i = 1; i < N; i++) {
        int U, V, W;
        cin >> U >> V >> W;
        g[U].push_back({V, W});
        g[V].push_back({U, W});
        result += W;
    }
    result *= 2;

    vector<bool> vis(N + 1);
    vector<int> distS(N + 1);
    queue<int> q({1});
    vis[1] = 1;
    
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto [v, w] : g[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                distS[v] = distS[u] + w;
                q.push(v);
            }
        }
    }
    
    cout << result - *max_element(all(distS));
}
