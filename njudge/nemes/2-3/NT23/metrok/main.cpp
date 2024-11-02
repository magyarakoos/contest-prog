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

    vector<bool> used_line(N + 1);
    vector<int> prev_station(M + 1);
    vector<int> reached_with_line(M + 1);
    vector<int> dist(M + 1, -1);
    dist[Ind] = 0;
    queue<int> q;
    q.push(Ind);

    while (!q.empty()) {
        int curr_station = q.front();
        q.pop();
        for (int line : station_to_lines[curr_station]) {
            if (used_line[line]) continue;
            used_line[line] = 1;
            for (int next_station :
                 line_to_stations[line]) {
                if (dist[next_station] != -1) continue;
                dist[next_station] = dist[curr_station] + 1;
                prev_station[next_station] = curr_station;
                reached_with_line[next_station] = line;
                q.push(next_station);
            }
        }
    }

    cout << dist[Erk] << '\n';
    if (dist[Erk] == -1) return 0;

    stack<int> res;
    int curr_station = Erk;
    while (curr_station != Ind) {
        res.push(reached_with_line[curr_station]);
        curr_station = prev_station[curr_station];
    }
    while (!res.empty()) {
        cout << res.top() << ' ';
        res.pop();
    }
}

