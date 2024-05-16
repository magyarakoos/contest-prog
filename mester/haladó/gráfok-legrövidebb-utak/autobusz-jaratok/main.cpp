#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    vector<vector<array<int, 2>>> g(N + 1);

    while (M--) {
        int U, V, W;
        cin >> U >> V >> W;
        g[U].push_back({V, W});
    }

    vector<ll> distS(N + 1, INF);
    vector<int> prv(N + 1);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    int S, E;
    cin >> S >> E;

    distS[S] = 0;
    pq.push({0, S});

    while (!pq.empty()) {
        auto [dist, u] = pq.top();
        pq.pop();
        if (dist != distS[u]) continue;
        for (auto [v, w] : g[u]) {
            if (dist + w < distS[v]) {
                distS[v] = dist + w;
                pq.push({dist + w, v});
                prv[v] = u;
            }
        }
    }

    cout << abs(distS[E]) << "\n";

    stack<int> s;
    while (1) {
        s.push(E);
        if (S == E) break;
        E = prv[E];
    }

    cout << s.size() << "\n";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n";
}