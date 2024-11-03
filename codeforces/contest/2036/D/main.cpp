#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

#define cases 1
void solve() {
    int N, M;
    cin >> N >> M;
    vector a(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c;
            cin >> c;
            a[i][j] = c - '0';
        }
    }
    int L = max(N, M);
    vector<vector<int>> top(L / 2), bottom(L / 2),
        left(L / 2), right(L / 2);
    for (int d = 0; d < N / 2; d++) {
        for (int j = 0; j < M - 2 * d; j++) {
            top[d].push_back(a[d][d + j]);
            bottom[d].push_back(a[N - d - 1][d + j]);
        }
        reverse(bottom[d].begin(), bottom[d].end());
    }
    for (int d = 0; d < M / 2; d++) {
        for (int i = 0; i < N - 2 * (d + 1); i++) {
            left[d].push_back(a[i + d + 1][d]);
            right[d].push_back(a[i + d + 1][M - d - 1]);
        }
        reverse(left[d].begin(), left[d].end());
    }

    // DB(top, bottom, left, right);

    int result = 0;
    for (int i = 0; i < L / 2; i++) {
        vector<int> layer;
        layer.insert(layer.end(), top[i].begin(),
                     top[i].end());
        layer.insert(layer.end(), right[i].begin(),
                     right[i].end());
        layer.insert(layer.end(), bottom[i].begin(),
                     bottom[i].end());
        layer.insert(layer.end(), left[i].begin(),
                     left[i].end());
        layer.insert(layer.end(), layer.begin(),
                     layer.begin() +
                         min(3, (int)layer.size()));
        for (int j = 3; j < layer.size(); j++) {
            result += layer[j - 3] == 1 &&
                      layer[j - 2] == 5 &&
                      layer[j - 1] == 4 && layer[j] == 3;
        }
    }

    cout << result << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
