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

    vector<vector<int>> g;
    vector<bool> has_father;
    int N;
    cin >> N;
    g.resize(N + 1);
    has_father.resize(N + 1);
    for (int i = 1; i < N; i++) {
        int U, V;
        cin >> U >> V;
        g[U].push_back(V);
        has_father[V] = 1;
    }

    int root;
    for (int i = 1 ; i <= N; i++) {
        if (!has_father[i]) {
            root = i;
            break;
        }
    }

    queue<int> q;
    q.push(root);
    int next;

    while (!q.empty()) {
        next = q.front();
        q.pop();
        for (int son : g[next]) {
            q.push(son);
        }
    }

    cout << next;
}
