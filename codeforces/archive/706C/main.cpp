#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define smin(x, y) x = min(x, y)

using namespace std;
using ll = long long;

constexpr ll INF = 1e15;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<int> costS(N);
    for (int& x : costS) cin >> x;

    vector<array<string, 2>> v(N);
    vector<array<ll, 2>> dp(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i][0];
        v[i][1] = v[i][0];
        reverse(all(v[i][1]));
    }

    dp[0] = {0, costS[0]};

    for (int i = 1; i < N; i++) {
        if (v[i - 1][0] <= v[i][0]) {
            smin(dp[i][0], dp[i - 1][0]);
        }
        if (v[i - 1][1] <= v[i][0]) {
            smin(dp[i][0], dp[i - 1][1]);
        }

        if (v[i - 1][0] <= v[i][1]) {
            smin(dp[i][1], dp[i - 1][0] + costS[i]);
        }
        if (v[i - 1][1] <= v[i][1]) {
            smin(dp[i][1], dp[i - 1][1])
        }
    }
}