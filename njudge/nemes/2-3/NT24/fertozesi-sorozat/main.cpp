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
    set<int> as(a.begin(), a.end());

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
        set<int> valueS;
        for (int i = 0; i < K; i++) {
            valueS.insert(order[i] = vis[a[i]]);
        }

        bool ok = 1;
        for (int i = 1; i < K; i++) {
            int d = order[i] - order[i - 1];
            ok = ok && (d == 0 || d == 1);
        }

        valueS.erase(valueS.begin());
        if (!valueS.empty()) {
            valueS.erase(*valueS.rbegin());
        }

        for (int u = 1; u <= N; u++) {
            ok = ok && !(!as.count(u) && valueS.count(u));
        }

        if (ok) { result.push_back(start); }
    }

    cout << result.size() << "\n";
    for (int x : result) cout << x << " ";
    cout << "\n";
}
