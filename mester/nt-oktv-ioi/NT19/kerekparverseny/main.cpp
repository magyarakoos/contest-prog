#include <iostream>
#include <vector>
#include <string>

typedef unsigned char u8;
typedef unsigned short u16;
using namespace std;

#define EVAL(m, x1, y1, x2, y2, v1) (abs(m[x1][y1] - m[x2][y2]) <= K ? v1 : 0)

int main() {
    u16 N, M, K;
    cin >> N >> M >> K;

    vector<vector<u16>> matrix(N, vector<u16>(M));

    for (u8 x = 0; x < N; x++) {
        for (u8 y = 0; y < M; y++) {
            cin >> matrix[x][y];
        }
    }

    /* create paths matrix & get best endpoint */
    vector<vector<u16>> paths(N, vector<u16>(M));

    paths[0][0] = 0;
    u8 max_x = 0, max_y = 0;

    for (u8 x = 1; x < N; x++) {
        paths[x][0] = EVAL(matrix, x-1, 0, x, 0, paths[x-1][0] + 1);
    }

    for (u8 y = 1; y < M; y++) {
        paths[0][y] = EVAL(matrix, 0, y-1, 0, y, paths[0][y-1] + 1);
    }

    for (u8 x = 1; x < N; x++) {        
        for (u8 y = 1; y < M; y++) {
            paths[x][y] = max(
                EVAL(matrix, x-1, y, x, y, paths[x-1][y] + 1),
                EVAL(matrix, x, y-1, x, y, paths[x][y-1] + 1)
            );

            if (paths[max_x][max_y] < paths[x][y]) {
                max_x = x; 
                max_y = y;
            }
        }
    }

    /* trace back startpoint & create route instructions */
    string route;
    route.reserve(paths[max_x][max_y]);
    u8 start_x = max_x, start_y = max_y;

    while (paths[start_x][start_y]) {
        if (start_x && EVAL(matrix, start_x-1, start_y, start_x, start_y, 1) && paths[start_x-1][start_y] + 1 == paths[start_x][start_y]) {
            start_x--;
            route = 'L' + route;
        } else {
            start_y--;
            route = 'J' + route;
        }
    }

    cout << paths[max_x][max_y] << '\n'
         << start_x + 1 << ' ' << start_y + 1 << '\n'
         << route;
}
