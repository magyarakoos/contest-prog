#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define vec vector
int N, M;

void solve(const vector<bool>& mask, const vec<vec<ll>>& col) {
    vec<ll> dp(N + 1);
    for (int j = 1; j <= N; j++) {
        dp[j] = LLONG_MAX;
        for (int k = 0; k < j; k++) {
            dp[j] = min(dp[j], dp[k] + col[k][j]);
        }
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> N >> M;
    vec<ll> rowS(N);
    vec<vec<vec<ll>>> colS(M, vec<vec<ll>>(N, vec<ll>(N)));

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
        vec<bool> mask(N);
        for (int j = 0; j < N; j++) {
            mask[j] = (i >> j) & 1;
        }
        ll curr = 0;

        

        res = min(res, curr);
    }
}