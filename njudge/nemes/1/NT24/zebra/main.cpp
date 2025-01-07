#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e9;

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;

    vector<array<int, 2>> a(N + 1);
    for (int i = 1; i <= N; i++) cin >> a[i][1];
    for (int i = 1; i <= N; i++) cin >> a[i][0];
    sort(a.begin() + 1, a.end());

    vector<int> sideA(1), sideB(1);
    for (int i = 1; i <= N; i++) {
        (a[i][1] ? sideB : sideA).push_back(a[i][0]);
    }
    int M = sideA.size() - 1, K = sideB.size() - 1;

    vector dp(M + 1, vector<int>(K + 1, INF));
    dp[0][0] = 0;

    vector<int> psA(M + 1), psB(M + 1);
    partial_sum(sideA.begin(), sideA.end(),
                psA.begin() + 1);
    partial_sum(sideB.begin(), sideB.end(),
                psB.begin() + 1);

    auto f = [&](int i, int j, int k, int l) {

    };

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= K; j++) {
            for (int k = 0; k < i; k++) {
                for (int l = 0; l < j; l++) {
                    dp[i][j] = min(
                        dp[i][j], dp[k][l] + f(i, j, k, l));
                }
            }
        }
    }
}
