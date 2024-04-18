#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using point = array<int, 2>;
constexpr int INF = 1e9, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

string path(point s, point p, const vector<vector<point>>& prv) {
    if (s == p) return "";
    point q = prv[p[1]][p[0]];
    char c = 'D';
    if (q[0] == p[0] + 1) c = 'L';
    if (q[0] + 1 == p[0]) c = 'R';
    if (q[1] == p[1] + 1) c = 'U';
    return path(s, q, prv) + c;
}

int main() {
	cin.tie(0), ios::sync_with_stdio(0);
    int N, M;
    cin >> N >> M;

    vector<vector<char>> g(N, vector<char>(M));
    vector<vector<int>>
        distS(N, vector<int>(M, INF)),
        MdistS(N, vector<int>(M, INF));
    vector<vector<point>>
        prv(N, vector<point>(M, {-1, -1}));
    vector<vector<bool>>
        vis(N, vector<bool>(M));
    point start;
    queue<point> q;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'A') {
                start = {j, i};
                distS[i][j] = 0;
            }
            if (g[i][j] == 'M') {
                q.push({j, i});
                MdistS[i][j] = 0;
                vis[i][j] = 1;
            }
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= M || ny >= N || 
                vis[ny][nx] || g[ny][nx] == '#') continue;
            
            vis[ny][nx] = 1;
            MdistS[ny][nx] = MdistS[y][x] + 1;
            q.push({nx, ny});
        }
    }

    q.push(start);

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        if (x == 0 || y == 0 || x == M - 1 || y == N - 1) {
            cout << "YES\n" << distS[y][x] << "\n" << path(start, {x, y}, prv);
            exit(0);
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (distS[ny][nx] < distS[y][x] + 1 || g[ny][nx] == '#' ||
               distS[y][x] + 1 >= MdistS[ny][nx]) continue;
            
            prv[ny][nx] = {x, y};
            distS[ny][nx] = distS[y][x] + 1;
            q.push({nx, ny});
        }
    }

    cout << "NO\n";
    exit(0);
}
