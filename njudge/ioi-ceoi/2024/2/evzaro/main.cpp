// O(N log N)
#include <bits/stdc++.h>
#define int ll
using namespace std;
using ll = long long;
using point = array<int, 2>;
constexpr int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

map<point, pair<int, char>> m;
vector<point> v;

void bfs(point s) {
    m[s].second = 'L';
    queue<pair<point, int>> q({{s, 0}});
    while (!q.empty()) {
        auto [pos, dist] = q.front(); q.pop();
        auto [x, y] = pos;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (!m.count({nx, ny}) || m[{nx, ny}].second) {
                continue;
            }
            m[{x, y}].second = (dist % 2 ? 'L' : 'F');
            q.push({{nx, ny}, dist + 1});
        }
    }
}

ifstream fin("in.txt");
ofstream fout("out.txt");
#define cin fin
#define cout fout

int32_t main() {
    //cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i][0] >> v[i][1];
        m[{v[i][0], v[i][1]}] = {i, 0};
    }

    for (int i = 0; i < N; i++) {
        if (!m[v[i]].second) {
            bfs(v[i]);
        }
        cout << m[v[i]].second;
    }
}
