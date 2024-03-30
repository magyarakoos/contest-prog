#include "labirintus.h"

std::vector<std::vector<int>> l;
constexpr int
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

    }


    for (int i = 0; i < N; i++) {
        l[U[i]][V[i]] = 0;
    }

    return false;
}
