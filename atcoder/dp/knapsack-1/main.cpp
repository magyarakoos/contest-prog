#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 100, MAXW = 1e5;

int N, W, v[MAXN], w[MAXN];
int m[MAXN][MAXW + 1];

ll solve(int i, ll weight) {
    if (i == N) return 0;
    if (m[i][weight] != -1) return m[i][weight];

    // don't take
    ll res = solve(i + 1, weight);

    // take
    if (weight + w[i] <= W) {
        res = max(res, solve(i + 1, weight + w[i]) + v[i]);
    }

    m[i][weight] = res;
    return res;
}

int main() {
    memset(m, -1, sizeof(m));
    cin.tie(0), ios::sync_with_stdio();
    cin >> N >> W;
    for (int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
    }
    cout << solve(0, 0);
}