#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};

int32_t main() {
    int N, M, Q, K = 0;
    cin >> N >> M >> Q;

    vector H(N, vector<int>(M));
    for (auto& row : H) {
        for (int& x : row) cin >> x;
    }

    vector<array<int, 5>> edgeS;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < 4; k++) {
                int ni = i + di[k], nj = j + dj[k];
                if (ni < 0 || nj < 0 || ni >= N ||
                    nj >= M) {
                    continue;
                }
                edgeS.push_back({max(H[i][j], H[ni][nj]), i,
                                 j, ni, nj});
                K++;
            }
        }
    }
    sort(edgeS.begin(), edgeS.end());

    auto h = [&](array<int, 2> a) -> int { return 0; };
    auto lca = [&](array<int, 2> a,
                   array<int, 2> b) -> array<int, 2> {
        return {};
    };

    while (Q--) {
        int i1, j1, i2, j2;
        cin >> i1 >> j1 >> i2 >> j2;
        i1--, j1--, i2--, j2--;
        cout << h({i1, j1}) + h({i2, j2}) -
                    2 * h(lca({i1, j1}, {i2, j2}))
             << "\n";
    }
}
