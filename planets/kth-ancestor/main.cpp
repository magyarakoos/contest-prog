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
        }
    }
}
