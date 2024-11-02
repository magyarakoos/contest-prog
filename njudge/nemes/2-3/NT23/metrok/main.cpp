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

    vector<vector<int>> stopS(M + 1), g(M + 1);
    vector<int> ind_nodeS, erk_nodeS;

    for (int i = 1, K, stop; i <= N; i++) {
        cin >> K;
        vector<int> line(K);
        bool ind_line = 0, erk_line = 0;

        for (int j = 0; j < K; j++) {
            cin >> line[j];
            stopS[line[j]].push_back(i);
            if (line[i] == Ind) ind_line = 1;
            if (line[i] == Erk) erk_line = 1;
        }

        if (ind_line) { ind_nodeS = line; }
        if (erk_line) { erk_nodeS = line; }
    }

    if (ind_nodeS.empty() || erk_nodeS.empty()) {
        cout << "-1\n";
        exit(0);
    }

    for (int stop = 1; stop <= M; stop++) {
        for (int i = 0; i < stopS[stop].size(); i++) {
            for (int j = 0; j < i; j++) {
                g[stopS[stop][i]].push_back(stopS[stop][j]);
                g[stopS[stop][j]].push_back(stopS[stop][i]);
            }
        }
    }

    set<int> erk_set(erk_nodeS.begin(), erk_nodeS.end());
    vector<int> distS(M + 1, INT_MAX);
    queue<int> q;

    for (int u : ind_nodeS) {
        q.push(u);
        distS[u] = 0;
    }
}
