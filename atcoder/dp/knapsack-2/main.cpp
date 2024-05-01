#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e12;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int N, W;
    cin >> N >> W;
    vector<int> v(N + 1), w(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> w[i] >> v[i];
    }

    int maxv = accumulate(v.begin(), v.end(), 0);

    vector dp(N + 1, vector<ll>(maxv + 1, INF));

    dp[0][0] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= maxv; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - v[i] >= 0) {
                auto& choose = dp[i - 1][j - v[i]];
                if (choose + w[i] <= W) {
                    dp[i][j] = min(dp[i][j], choose + w[i]);
                }
            }
        }
    }

    for (int j = maxv; j >= 0; j--) {
        if (dp[N][j] != -1) {
            cout << j;
            exit(0);
        }
    }
}