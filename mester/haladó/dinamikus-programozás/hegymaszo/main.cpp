#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 1e5;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, T, H;
    cin >> N >> T >> H;
    vector<array<int, 2>> v(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> v[i][0] >> v[i][1];
    }
    v[N] = {T, 0};

    vector<array<int, 2>> dp(N + 1, {INF, INF});
    dp[0] = {1, v[1][1]};

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < i; j++) {
            if (v[i][0] - v[j][0] <= dp[j][1]) {
                if (dp[j][0] + 1 < dp[i][0]) {
                    
                }
            }
        }
    }
}