#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e5, MAXM = 5;

int lg[MAXN + 1], st[MAXM][25][MAXN];

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int>> droids(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) { cin >> droids[i][j]; }
    }

    for (int i = 2; i <= MAXN; i++) { lg[i] = lg[i / 2] + 1; }

    for (int i = 1; i < 25; i++) {
        for (int j = 0; j + (1 << i) <= N; i++) {
            st[i][j] =
                max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
    }

    auto rmq = [&](int i, int l, int r) -> int {
        int j = lg[r - l + 1];
        return max(st[i][j][l], st[i][j][r - (1 << j) + 1]);
    };

    auto f = [&](int l, int r) -> bool {
        if (l > r) return 1;
        int result = 0;
        for (int i = 0; i < M; i++) { result += rmq() }
        return result <= K;
    };

    for (int i = 0; i < N; i++) {
        int l = 0, r = i + 1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (f(m, i)) {
                r = m;
            } else {
                l = m;
            }
        }
    }
}
