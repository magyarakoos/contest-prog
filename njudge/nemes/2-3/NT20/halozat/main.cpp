#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)
#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define has(s, e) s.count(e)

using namespace std;
using ll = long long;
using point = array<int, 2>;

int main() {
    speed;

    int N, M, K;
    cin >> N >> M >> K;

    vector<unordered_set<int>> g(N + 1);
    
    while (M--) {
        int U, V;
        cin >> U >> V;
        g[U].insert(V);
        g[V].insert(U);
    }

    queue<int> todo;
    for (int i = 1; i <= N; i++) {
        if (g[i].size() < K) {
            todo.push(i);
        }
    }

    while (!todo.empty()) {
        int next = todo.front(); todo.pop();

        for (int neigh : g[next]) {
            g[neigh].erase(next);
            if (g[neigh].size() < K) {
                todo.push(neigh);
            }
        }
    }

    vector<int> result;

    for (int i = 1; i <= N; i++) {
        if (g[i].size() >= K) {
            result.push_back(i);
        }
    }

    cout << result.size() << '\n';
    for (int x : result) cout << x << ' ';
    cout << '\n';
}
