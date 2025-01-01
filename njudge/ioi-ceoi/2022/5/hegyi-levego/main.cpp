#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1},
          MAXK = 25;

int32_t main() {
    int N, M, Q;
    cin >> N >> M >> Q;

    vector H(N, vector<int>(M));
    for (auto& row : H) {
        for (int& x : row) cin >> x;
    }

    vector<array<int, 5>> edgeS;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < 4; k++) {
                int ni = i + di[k], nj = j + dj[k];
                if (ni < 0 || nj < 0 || ni >= N ||
                    nj >= M) {
                    continue;
                }
                edgeS.push_back({max(H[i][j], H[ni][nj]), i,
                                 j, ni, nj});
            }
        }
    }
    sort(edgeS.begin(), edgeS.end());

    vector rnk(N, vector<int>(M, 1));
    vector par(N, vector<array<int, 2>>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) { par[i][j] = {i, j}; }
    }

    function<array<int, 2>(array<int, 2>)> find =
        [&](array<int, 2> a) -> array<int, 2> {
        if (a == par[a[0]][a[1]]) return a;
        return par[a[0]][a[1]] = find(par[a[0]][a[1]]);
    };
    auto same = [&](array<int, 2> a,
                    array<int, 2> b) -> bool {
        return find(a) == find(b);
    };
    auto unite = [&](array<int, 2> a,
                     array<int, 2> b) -> void {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (rnk[a[0]][a[1]] < rnk[b[0]][b[1]]) {
                swap(a, b);
            }
            rnk[a[0]][a[1]] += rnk[b[0]][b[1]];
            par[b[0]][b[1]] = a;
        }
    };

    vector m(N, vector<vector<array<int, 3>>>(M));

    for (auto [w, i1, j1, i2, j2] : edgeS) {
        if (!same({i1, j1}, {i2, j2})) {
            unite({i1, j1}, {i2, j2});
            m[i1][j1].push_back({i2, j2, w});
            m[i2][j2].push_back({i1, j1, w});
        }
    }

    vector st(MAXK, vector<vector<int>>(N, vector<int>(M)));

    auto dfs = [&](const auto& self, array<int, 2> a) {

    };

    auto h = [&](array<int, 2> a) -> int { return 0; };
    auto lca = [&](array<int, 2> a,
                   array<int, 2> b) -> array<int, 2> {
        return {};
    };

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << i * 2 << " " << j * 2 << "\n";
            for (auto [ni, nj, w] : m[i][j]) {
                cout << (i * 2 + ni * 2) / 2 << " "
                     << (j * 2 + nj * 2) / 2 << "\n";
            }
        }
    }

    while (Q--) {
        int i1, j1, i2, j2;
        cin >> i1 >> j1 >> i2 >> j2;
        i1--, j1--, i2--, j2--;
        cout << h({i1, j1}) + h({i2, j2}) -
                    2 * h(lca({i1, j1}, {i2, j2}))
             << "\n";
    }
}
