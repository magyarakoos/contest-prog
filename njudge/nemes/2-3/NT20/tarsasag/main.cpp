#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)
#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define has(s, e) s.count(e)

using namespace std;
using ll = long long;
using point = array<int, 2>;

struct Route {
public:
    int node;
    int weight;
    bool operator()(Route a, Route b) {
        return a.weight > b.weight;
    }
};

int main() {
    speed;

    vector<vector<point>> g;

    int N, K;
    cin >> N >> K;
    
    g.resize(N + 1);
    for (int i = 2; i <= N; i++) {
        int V, W;
        cin >> V >> W;
        g[V].push_back({i, -W});
    }

    priority_queue<Route, vector<Route>, Route> pq;
    vector<ll> distS(N + 1, INT_MAX);
    vector<int> prevS(N + 1);
    vector<bool> vis(N + 1);

    pq.push({1, 0});
    distS[1] = 0;

    while (!pq.empty()) {
        auto [node, weight] = pq.top();
        pq.pop();

        if (distS[node] < weight) continue;

        for (auto [next_node, next_weight] : g[node]) {
            if (vis[next_node]) continue;
            vis[next_node] = 1;

            int dist = weight + next_weight;

            if (dist < distS[next_node]) {
                distS[next_node] = dist;
                prevS[next_node] = node;
                pq.push({next_node, dist});
            }
        }
    }

    ll longest = min_element(all(distS)) - distS.begin(),
        sum = 0, next = longest;
    
    vector<ll> path;
    cout << '\n';
    while (prevS[next] != 0) {
        for (point p : g[prevS[next]]) {
            if (p[0] == next) {
                cout << -p[1] << '\n';
                sum += -p[1];
                path.push_back(-p[1]);
                break;
            }
        }
        next = prevS[next];
    }
    
    sort(all(path));
    
    if (K >= path.size()) {
        cout << 0;
        exit(0);
    }

    for (int i = path.size() - 1; i >= path.size() - K; i--) {
        sum -= path[i];
    }

    cout << sum;
}
