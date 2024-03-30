#include "labirintus.h"

#include <cassert>
#include <cstdio>

#include <vector>

int main() {
    int R, C, Q;
    assert(3 == scanf("%d %d %d", &R, &C, &Q));

    std::vector<std::vector<int>> labyrinth(R, std::vector<int>(C));
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            char c;
            assert(1 == scanf(" %c", &c));
            labyrinth[i][j] = c - '0';
        }
    }
    init_labyrinth(R, C, labyrinth);

    std::vector<int> answers(Q);
    for (int i = 0; i < Q; ++i) {
        int N;
        assert(1 == scanf("%d", &N));
        std::vector<int> U(N), V(N);
        for (int j = 0; j < N; ++j) {
            assert(2 == scanf("%d %d", &U[j], &V[j]));
        }
        answers[i] = can_escape(N, U, V);
    }

    for (int i = 0; i < Q; ++i) {
        printf("%d\n", answers[i]);
    }

    return 0;
}
