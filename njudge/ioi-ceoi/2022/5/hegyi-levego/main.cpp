// holy fucking fuck this was so fucking tedious
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

    vector m(N, vector<vector<array<int, 2>>>(M));
    vector weightS(N, vector<vector<int>>(M));

    for (auto [w, i1, j1, i2, j2] : edgeS) {
        if (!same({i1, j1}, {i2, j2})) {
            unite({i1, j1}, {i2, j2});
            m[i1][j1].push_back({i2, j2});
            weightS[i1][j1].push_back(w);
            m[i2][j2].push_back({i1, j1});
            weightS[i2][j2].push_back(w);
        }
    }

    vector st(MAXK, vector<vector<array<int, 2>>>(
                        N, vector<array<int, 2>>(M)));
    vector dp(MAXK, vector<vector<int>>(M));
    vector tin(N, vector<int>(M)), tout(N, vector<int>(M));
    vector height(N, vector<int>(M));

    int timer;
    function<void(array<int, 2>, array<int, 2>)> dfs =
        [&](array<int, 2> u, array<int, 2> p) {
            tin[u[0]][u[1]] = ++timer;
            st[0][u[0]][u[1]] = p;
            for (int i = 1; i < MAXK; i++) {
                array<int, 2> up = st[i - 1][u[0]][u[1]];
                st[i][u[0]][u[1]] = st[i - 1][up[0]][up[1]];
            }
            for (int i = 0; i < m[u[0]][u[1]].size(); i++) {
                auto v = m[u[0]][u[1]][i];
                if (v != p) {
                    height[v[0]][v[1]] =
                        height[u[0]][u[1]] + 1;
                    dfs(v, u);
                }
            }
            tout[u[0]][u[1]] = ++timer;
        };
    auto h = [&](array<int, 2> a) -> int {
        return height[a[0]][a[1]];
    };
    auto is_anc = [&](array<int, 2> a,
                      array<int, 2> b) -> bool {
        return tin[a[0]][a[1]] <= tin[b[0]][b[1]] &&
               tout[b[0]][b[1]] <= tout[a[0]][a[1]];
    };
    auto lca = [&](array<int, 2> a,
                   array<int, 2> b) -> array<int, 2> {
        if (is_anc(a, b)) return a;
        if (is_anc(b, a)) return b;
        for (int i = MAXK - 1; i >= 0; i--) {
            if (!is_anc(a, b)) a = st[i][a[0]][a[1]];
        }
        return st[0][a[0]][a[1]];
    };

    timer = 0;
    dfs({0, 0}, {0, 0});

    /*for (int i = 0; i < N; i++) {*/
    /*    for (int j = 0; j < M; j++) {*/
    /*        cout << setw(2) << h({i, j}) << " ";*/
    /*    }*/
    /*    cout << "\n";*/
    /*}*/

    while (Q--) {
        int i1, j1, i2, j2;
        cin >> i1 >> j1 >> i2 >> j2;
        i1--, j1--, i2--, j2--;
        cout << max(h({i1, j1}), h({i2, j2})) << "\n";
    }
}
