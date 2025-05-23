#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, M, K;
    cin >> N >> M >> K;

    vector<int> a(K);
    for (int& x : a) cin >> x;
    set<int> aSet(a.begin(), a.end());

    vector<vector<int>> g(N + 1);
    while (M--) {
        int U, V;
        cin >> U >> V;
        g[U].push_back(V);
        g[V].push_back(U);
    }

    vector<int> result;
    for (int start = 1; start <= N; start++) {
        vector<int> vis(N + 1);
        vis[start] = 1;
        queue<int> q({start});

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : g[u]) {
                if (!vis[v]) {
                    vis[v] = vis[u] + 1;
                    q.push(v);
                }
            }
        }

        vector<int> order(K);
        set<int> orderSet;
        for (int i = 0; i < K; i++) {
            orderSet.insert(order[i] = vis[a[i]]);
        }

        bool ok = 1;
        for (int i = 1; i < K; i++) {
            int d = order[i] - order[i - 1];
            ok = ok && (d == 0 || d == 1);
        }

        orderSet.erase(orderSet.begin());
        if (!orderSet.empty()) {
            orderSet.erase(*orderSet.rbegin());
        }

        for (int u = 1; u <= N; u++) {
            ok = ok && !(!aSet.count(u) &&
                         orderSet.count(vis[u]));
        }

        if (ok) { result.push_back(start); }
    }

    cout << result.size() << "\n";
    for (int x : result) cout << x << " ";
    cout << "\n";
}

