#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio();
    int N, W;
    cin >> N >> W;

    vector<int> w(N), v(N);
    vector dp(N, vector<ll>(W + 1, -1));

    for (int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
    }

    dp[0][0] = 0;

    for (int i = 0; i < N; i++) {
        for (int j = W; j >= 0; j--) {
            dp[i][j] = dp[i - 1][j];
            if ()
        }
    }
}