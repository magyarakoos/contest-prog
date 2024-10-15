#include "debug.h"
#include <iostream>
#include <vector>

using namespace std;
const int MAXK = 20;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, Q;
    cin >> N >> Q;

    vector<vector<int>> p(MAXK, vector<int>(N + 1, 0));
    while (Q--) {
        int type;
        cin >> type;
        if (type == 0) {
            int Y, X;
            cin >> Y >> X;
            p[1][X] = Y;
            for (int i = 1; (1 << i) < MAXK; i++) {
                p[1 << i][X] = p[1 << (i - 1)][p[1 << (i - 1)][X]];
            }
        }
        if (type == 1) {
            int X;
            cin >> X;
            for (int i = 1; i < MAXK; i++) p[i][X] = 0;
        }
        if (type == 2) {
            int X, K;
            cin >> X >> K;
            // cout << p[K][X] << "\n";
        }
        DB(p);
    }
}
