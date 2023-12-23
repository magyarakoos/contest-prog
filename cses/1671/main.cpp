#include <bits/stdc++.h>
#define speed cin.tie(0); ios::sync_with_stdio(0)

using namespace std;
using ll = unsigned long long;

struct Route {
public:
    int node;
    ll length;
    bool operator()(Route a, Route b) {
        return a.length > b.length;
    }
};

int main() {
    speed;
    int N, M;
    cin >> N >> M;

    vector<vector<Route>> neighborS(N + 1);

    while (M--) {
        int U, V;
        ll L;
        cin >> U >> V >> L;
        neighborS[U].push_back({V, L});
    }

    vector<ll> distanceS(N + 1, ULLONG_MAX);

    priority_queue<Route, vector<Route>, Route> pq;

    pq.push({1, 0});
    distanceS[1] = 0;

    while (!pq.empty()) {
        Route next = pq.top(); 
        pq.pop();

        // already found a shorter way to get to the 'next' node,
        // so it's pointless to check any further
        if (next.length != distanceS[next.node]) continue;

        for (const Route& neighbor : neighborS[next.node]) {

            ll dist = distanceS[next.node] + neighbor.length;

            if (dist < distanceS[neighbor.node]) {

                distanceS[neighbor.node] = dist;
                pq.push({neighbor.node, dist});
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << distanceS[i] << ' ';
    }
}
