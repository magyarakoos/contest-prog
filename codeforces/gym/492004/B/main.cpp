#include <bits/stdc++.h>

#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

constexpr int INF = 1e9;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, D;
    cin >> N >> D;

    vector<int> dp(N + 1, INF);
    for (int i = 1; i <= N; i++) {
        char b;
        cin >> b;
        if (b == '0') {
            dp[i] = -1;
        }
    }

    dp[1] = 0;

    for (int i = 2; i <= N; i++) {
        if (dp[i] == -1) {
            continue;
        }

        for (int j = max(i - D, 1); j < i; j++) {
            if (dp[j] != -1) {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }

    cout << (dp[N] == INF ? -1 : dp[N]);
}