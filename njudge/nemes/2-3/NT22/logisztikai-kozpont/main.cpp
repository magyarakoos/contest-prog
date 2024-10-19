#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<vector<array<int, 3>>> g;
vector<ll> dp;

int main() {
    int N;
    cin >> N;

    g.resize(N + 1);
    dp.resize(N + 1);

    for (int i = 0; i < N - 1; i++) {
        int U, V, W;
        cin >> U >> V >> W;
        g[U].push_back({V, W});
        g[V].push_back({U, W});
    }

    dfs(1);
}
