#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector a(N, vector<int>(N)), ps(N + 1, vector<int>(N + 1));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c;
            cin >> c;
            a[i][j] = c == '*';
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            ps[i][j] = ps[i][j - 1] + a[i - 1][j - 1];
        }
    }

    for (int j = 1; j <= N; j++) {
        for (int i = 1; i <= N; i++) {
            ps[i][j] += ps[i - 1][j];
        }
    }

    while (Q--) {
        int i1, j1, i2, j2;
        cin >> i1 >> j1 >> i2 >> j2;
        cout << ps[i2][j2] + ps[i1 - 1][j1 - 1] - ps[i2][j1 - 1] -
                    ps[i1 - 1][j2]
             << "\n";
    }
}
