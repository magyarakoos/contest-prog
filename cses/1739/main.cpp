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

    BIT2D(int n, int m, const vector<vector<int>>& a) : BIT2D(n, m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                add(i, j, a[i][j]);
            }
        }
    }

    void add(int i, int j, int delta) {
        while (i < n) {
            add_j(i, j, delta);
            i += (i & -i);
        }
    }

    int sum(int i, int j) {
        int ret = 0;
        for (; ~i; i--) {
            ret += read_j(i, j);
        }
        return ret;
    }

    int sum(int i1, int j1, int i2, int j2) {
        return sum(i2, j2) - sum(i2, j1 - 1) - sum(i1 - 1, j2) + sum(i1, j1);
    }

   private:
    void add_j(int i, int j, int delta) {
        while (j < m) {
            t[i][j] += delta;
            j += (j & -j);
        }
    }

    int read_j(int i, int j) {
        int ret = 0;
        while (j >= 0) {
            ret += t[i][j];
            j -= (j & -j);
        }
        return ret;
    }
};

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, Q;
    cin >> N >> Q;

    vector grid(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c;
            cin >> c;
            grid[i][j] = c == '*';
        }
    }

    BIT2D bit{N, N, grid};

    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int i, j;
            cin >> i >> j;
            bit.add(i - 1, j - 1, grid[i][j] ? -1 : 1);
        } else {
            int i1, j1, i2, j2;
            cin >> i1 >> j1 >> i2 >> j2;
            cout << bit.sum(i1 - 1, j1 - 1, i2 - 1, j2 - 1) << "\n";
        }
    }
}
