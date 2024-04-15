#include <bits/stdc++.h>
using namespace std;
constexpr int MOD = 1e9 + 7;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> g(N + 1);
    vector<bool> vis(N + 1);
    vector<int> dp(N + 1);
    while (M--) {
        int U, V;
        cin >> U >> V;
        g[U].push_back(V);
    }
    queue<int> q({1});
    vis[1] = dp[1] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        
    }
}
