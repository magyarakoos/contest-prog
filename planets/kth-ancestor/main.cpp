#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, Q;
    cin >> N >> Q;

    vector<vector<int>> p(20, vector<int>(N + 1, 0));
    while (Q--) {
        int type;
        cin >> type;
        if (type == 0) {
            int Y, X;
            cin >> Y >> X;
            p[1][X] = Y;
            p[2][X] = p[1][p[1][X]];
        }
        if (type == 1) {
            int X;
            cin >> X;
            for (int i = 1; i < 20; i++) p[i][X] = 0;
        }
        if (type == 2) {
            int X, K;
            cin >> X >> K;
            cout << p[K][X] << "\n";
        }
    }
}
