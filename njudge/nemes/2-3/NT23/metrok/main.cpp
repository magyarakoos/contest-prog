#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, M, Ind, Erk;
    cin >> N >> M >> Ind >> Erk;

    vector<vector<int>> station_to_lines(M + 1),
        line_to_stations(N + 1);
    for (int i = 1; i <= N; i++) {
        int A;
        cin >> A;
        while (A--) {
            int stop;
            cin >> stop;
            line_to_stations[i].push_back(stop);
            station_to_lines[stop].push_back(i);
        }
    }

    vector<int> prv_node(M + 1), prv_line(M + 1),
        distS(M + 1, -1), vis(N + 1);
    queue<int> q({Ind});

    distS[Ind] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : station_to_lines[u]) {
            if (vis[v]) continue;
            vis[v] = 1;
            for (int next_station : line_to_stations[v]) {
                if (distS[next_station] != -1) continue;
                distS[next_station] = distS[u] + 1;
                prv_node[next_station] = u;
                prv_line[next_station] = v;
                q.push(next_station);
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
        Erk = prv_node[Erk];
    }

    for (int x : path) cout << x << " ";
    cout << "\n";
}

