#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)
#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define has(s, e) s.count(e)

using namespace std;
using ll = long long;
using point = array<int, 2>;

map<int, unordered_set<int>> g;
vector<vector<int>> groupS;
vector<bool> vis;

void dfs(int n) {
    vis[n] = 1;
    groupS.back().push_back(n);
    for (int neigh : g[n]) {
        if (!vis[neigh]) {
            dfs(neigh);
        }
    }
}

int main() {
    speed;

    int N, M, K;
    cin >> N >> M >> K;


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
        g.erase(next);
    }

    vis.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        if (!vis[i]) {
            groupS.push_back({});
            dfs(i);
        }
    }

    vector<int>& mx = *max_element(all(groupS), 
    [](const vector<int>& a, const vector<int>& b){ return a.size() < b.size(); });

    cout << mx.size() << '\n';

    sort(all(mx));
    for (int n : mx) {
        cout << n << ' ';
    }
}
