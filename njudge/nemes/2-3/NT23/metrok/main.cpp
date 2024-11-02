#include <climits>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

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
    }

    if (!ind_line || erk_line) {
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

    vector<int> distS(N + 1, INT_MAX), vis(N + 1),
        prv(N + 1);
    queue<int> q({ind_line});
    vis[ind_line] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == erk_line) break;
        for (int v : g[u]) {
            if (!vis[v]) { prv[v] = u; }
        }
    }
}
