#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define vec vector
int N, M;

ll solve(const vector<bool>& mask, const vec<vec<ll>>& col) {
    vec<ll> dp(N + 1, LLONG_MAX);
    dp[0] = 0;
    for (int j = 1; j <= N; j++) {
        if (mask[j - 1]) {
            dp[j] = dp[j - 1];
        }
        for (int k = 0; k < j; k++) {
            dp[j] = min(dp[j], dp[k] + col[k][j - 1]);
        }
    }
    return dp[N];
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> N >> M;
    vec<ll> rowS(N + 1);
    vec<vec<vec<ll>>> colS(M + 1, vec<vec<ll>>(N, vec<ll>(N)));

    for (int i = 0; i < N; i++) {
        cin >> rowS[i];
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = j; k < N; k++) {
                cin >> colS[i][j][k];
            }
        }
    }

    ll res = LLONG_MAX;
    for (int i = 0; i < (1 << N); i++) {
        ll curr = 0;
        vec<bool> mask(N);
        for (int j = 0; j < N; j++) {
            mask[j] = (i >> j) & 1;
            if (mask[j]) curr += rowS[j];
        }

        for (int j = 0; j < M; j++) {
            curr += solve(mask, colS[j]);
        }

        res = min(res, curr);
    }

    cout << res;
}