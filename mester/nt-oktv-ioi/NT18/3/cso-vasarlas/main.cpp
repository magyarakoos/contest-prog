#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

constexpr int INF = 1e9;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    vector<array<int, 2>> pipeS(N);
    for (int i = 0; i < N; i++) {
        cin >> pipeS[i][0] >> pipeS[i][1];
    }

    vector<int> dp(M + 1);

    for (int i = 1; i <= M; i++) {
        dp[i] = INF;
        for (auto [H, A] : pipeS) {
            if (i >= H) {
                dp[i] = min(dp[i], dp[i - H] + A);
            }
        }
    }

    cout << dp[M];
}