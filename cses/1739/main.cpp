#include <iostream>
#include <vector>

using namespace std;

struct BIT2D {
    vector<vector<int>> t;
    int n, m;

    BIT2D(int n, int m) : t(n, vector<int>(m, 0)) {
        this->n = n;
        this->m = m;
    }

    int sum(int x, int y) {
        int ret = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
            for (int j = y; j >= 0; j = (j & (j + 1)) - 1) ret += t[i][j];
        return ret;
    }

    int sum(int i1, int j1, int i2, int j2) {
        return sum(i2, j2) - sum(i2, j1 - 1) - sum(i1 - 1, j2) +
               sum(i1 - 1, j1 - 1);
    }

    void add(int x, int y, int delta) {
        for (int i = x; i < n; i = i | (i + 1))
            for (int j = y; j < m; j = j | (j + 1)) t[i][j] += delta;
    }
};

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, Q;
    cin >> N >> Q;

    vector grid(N, vector<int>(N));
    BIT2D bit(N, N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c;
            cin >> c;
            if (c == '*') {
                bit.add(i, j, 1);
                grid[i][j] = 1;
            }
        }
    }

    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int i, j;
            cin >> i >> j;
            bit.add(i - 1, j - 1, grid[i - 1][j - 1] ? -1 : 1);
            grid[i - 1][j - 1] = !grid[i - 1][j - 1];
        } else {
            int i1, j1, i2, j2;
            cin >> i1 >> j1 >> i2 >> j2;
            cout << bit.sum(i1 - 1, j1 - 1, i2 - 1, j2 - 1) << "\n";
        }
    }
}
