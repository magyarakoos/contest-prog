#include "labirintus.h"

std::vector<std::vector<int>> l;
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
    

    for (int i = 0; i < N; i++) {
        l[U[i]][V[i]] = 0;
    }

    return false;
}
