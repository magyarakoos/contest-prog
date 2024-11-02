#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, M, Ind, Erk;
    cin >> N >> M >> Ind >> Erk;

    vector<vector<int>> stopS(M + 1), lineS(N + 1);
    for (int i = 1; i <= N; i++) {
        int A;
        cin >> A;
        while (A--) {
            int stop;
            cin >> stop;
            lineS[i].push_back(stop);
            stopS[stop].push_back(i);
        }
    }

    vector<int> prv_stop(M + 1), prv_line(M + 1),
        distS(M + 1, -1), vis(N + 1);
    queue<int> q({Ind});

    distS[Ind] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : stopS[u]) {
            if (vis[v]) continue;
            vis[v] = 1;
            for (int l : lineS[v]) {
                if (distS[l] != -1) continue;
                distS[l] = distS[u] + 1;
                prv_stop[l] = u;
                prv_line[l] = v;
                q.push(l);
            }
        }
    }

    if (distS[Erk] == -1) {
        cout << "-1\n";
        exit(0);
    }

    cout << distS[Erk] << "\n";

    deque<int> path;
    while (Erk != Ind) {
        path.push_front(prv_line[Erk]);
        Erk = prv_stop[Erk];
    }

    for (int x : path) cout << x << " ";
    cout << "\n";
}

