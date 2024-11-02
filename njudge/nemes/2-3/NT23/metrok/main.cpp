#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, M, Ind, Erk;
    cin >> N >> M >> Ind >> Erk;

    vector<vector<int>> stopS(M + 1);
    int ind_line = 0, erk_line = 0;

    for (int i = 1, K, stop; i <= N; i++) {
        cin >> K;
        vector<int> line(K);

        for (int j = 0; j < K; j++) {
            cin >> line[j];
            stopS[line[j]].push_back(i);
            if (line[j] == Ind) ind_line = i;
            if (line[j] == Erk) erk_line = i;
        }

        if (ind_line == i && erk_line == i) {
            cout << "1\n" << i << "\n";
            exit(0);
        }
    }

    if (!ind_line || !erk_line) {
        cout << "-1\n";
        exit(0);
    }

    vector m(N + 1, vector<bool>(N + 1));

    for (int stop = 1; stop <= M; stop++) {
        for (int i = 0; i < stopS[stop].size(); i++) {
            for (int j = 0; j < i; j++) {
                m[stopS[stop][i]][stopS[stop][j]] = 1;
                m[stopS[stop][j]][stopS[stop][i]] = 1;
            }
        }
    }

    vector<int> distS(N + 1, INT_MAX), prv(N + 1);
    queue<int> q({ind_line});

    distS[ind_line] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == erk_line) break;
        for (int v = 1; v <= N; v++) {
            if (!m[u][v]) continue;
            vis[v] = 1;
            prv[v] = u;
            distS[v] = distS[u] + 1;
            q.push(v);
        }
    }

    if (distS[erk_line] == INT_MAX) {
        cout << "-1\n";
        exit(0);
    }

    deque<int> path;
    while (1) {
        path.push_front(erk_line);
        if (erk_line == ind_line) break;
        erk_line = prv[erk_line];
    }

    cout << path.size() << "\n";
    for (int x : path) cout << x << " ";
    cout << "\n";
}
