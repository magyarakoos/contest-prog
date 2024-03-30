#include "labirintus.h"

std::vector<std::vector<int>> l;
constexpr int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int r, c;


void init_labyrinth(int R, int C, std::vector<std::vector<int>> L) {
    l = L;
    r = R;
    c = C;
}

bool can_escape(int N, std::vector<int> U, std::vector<int> V) {

    for (int i = 0; i < N; i++) {
        l[U[i]][V[i]] = 1;
    }

    std::vector<std::vector<bool>> vis(r, std::vector<bool>(c));
    std::queue<std::array<int, 2>> q({{0, 0}});
    vis[0][0] = 1;

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        if (x == c - 1 && y == r - 1) {
            for (int i = 0; i < N; i++) {
                l[U[i]][V[i]] = 0;
            };
            return true;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= c || ny >= r || l[ny][nx]) {
                continue;
            }
            if (!vis[ny][nx]) {
                vis[ny][nx] = 1;
                q.push({nx, ny});
            }
        }
    }

    for (int i = 0; i < N; i++) {
        l[U[i]][V[i]] = 0;
    }

    return false;
}
