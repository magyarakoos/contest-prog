#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;
using edge = struct { int node; int w; };

constexpr int INF = 1e9;

vector<vector<edge>> g;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;

    g.resize(N + 1);

    for (int i = 1; i < N; i++) {
        int U, V, W;
        cin >> U >> V >> W;

        g[U].push_back({V, W});
        g[V].push_back({U, W});
    }

    for (int s = 1; s <= N; s++) {

        vector<int> distS(N + 1, INF);
        distS[s] = 0;

        queue<edge> q;
        q.push({s, 0});

        while (!q.empty()) {
            auto []
        }
    }
}