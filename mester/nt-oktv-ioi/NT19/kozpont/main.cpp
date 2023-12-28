#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)
#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define has(s, e) s.count(e)

using namespace std;
using ll = long long;
using point = array<int, 2>;

// why the fuck is this not giving the correct answer
int main() {
    speed;

    int N, K;
    cin >> N >> K;

    vector<vector<point>> g(N + 1);
    while (K--) {
        int U, V, W;
        cin >> U >> V >> W;
        g[U].push_back({-W, V});
    }

    int result = 0, result_v = 0;

    for (int s = 1; s <= N; s++) {
        priority_queue<point, vector<point>, greater<point>> pq;
        vector<int> distS(N + 1, INT_MAX);
        vector<bool> vis(N + 1);

        distS[0] = 0;

        pq.push({INT_MIN, s});
        distS[s] = 0;
        vis[s] = 1;

        while (!pq.empty()) {
            auto [weight, node] = pq.top();
            pq.pop();

            if (distS[node] < weight) continue;

            for (auto[next_weight, next_node] : g[node]) {

                if (vis[next_node]) continue;

                int new_weight = max(weight, next_weight);

                if (new_weight < distS[next_node]) {

                    distS[next_node] = new_weight;
                    pq.push({new_weight, next_node});
                }
            }
        }

        int rate = accumulate(all(distS), 0);

        cout << s << ' ' << rate << '\n';   

        if (rate < result_v) {
            result_v = rate;
            result = s;
        }
    }

    cout << result;
}
