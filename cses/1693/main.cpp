#include <deque>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> g;
vector<int> in, out;
deque<int> path;

bool path_exists() {
    if (!(out[1] - in[1] == 1 && in[N] - out[N] == 1)) return 0;
    for (int u = 2; u < N; u++) {
        if (in[u] != out[u]) return 0;
    }
    return 1;
}

void dfs(int u) {
    while (out[u]) {
        dfs(g[u][--out[u]]);
    }
    path.push_front(u);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    cin >> N >> M;

    g.resize(N + 1);
    in.resize(N + 1);
    out.resize(N + 1);
    
    for (int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;
        g[U].push_back(V);
        out[U]++;
        in[V]++;
    }

    if (!path_exists()) {
        cout << "IMPOSSIBLE\n";
        exit(0);
    }

    dfs(1);

    if (path.size() != M + 1) {
        cout << "IMPOSSIBLE\n";
        exit(0);
    }

    for (int x : path) cout << x << " ";
    cout << "\n";
}
