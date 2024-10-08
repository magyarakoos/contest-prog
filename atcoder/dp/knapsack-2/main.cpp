#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e15;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int N, W;
    cin >> N >> W;
    vector<int> v(N + 1), w(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> w[i] >> v[i];
    }

    int maxv = accumulate(v.begin(), v.end(), 0);

    vector<ll> dp(maxv + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = maxv; j >= 0; j--) {
            if (j - v[i] >= 0) {
                dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
            }
        }
    }

    for (int j = maxv; j >= 0; j--) {
        if (dp[j] <= W) {
            cout << j;
            exit(0);
        }
    }
}
