#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, M, Ind, Erk;
    cin >> N >> M >> Ind >> Erk;

    vector<vector<int>> station_to_lines(M + 1);
    vector<vector<int>> line_to_stations(N + 1);
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

    vector<int> prv(M + 1), distS(M + 1, -1), vis(N + 1);
    vector<int> reached_with_line(M + 1);
    queue<int> q({Ind});

    distS[Ind] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int line : station_to_lines[u]) {
            if (vis[line]) continue;
            vis[line] = 1;
            for (int next_station :
                 line_to_stations[line]) {
                if (distS[next_station] != -1) continue;
                distS[next_station] = distS[u] + 1;
                prv[next_station] = u;
                reached_with_line[next_station] = line;
                q.push(next_station);
            }
        }
    }

    cout << distS[Erk] << '\n';
    if (distS[Erk] == -1) return 0;

    stack<int> res;
    int curr_station = Erk;
    while (curr_station != Ind) {
        res.push(reached_with_line[curr_station]);
        curr_station = prv[curr_station];
    }
    while (!res.empty()) {
        cout << res.top() << ' ';
        res.pop();
    }
}

