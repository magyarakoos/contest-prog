#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)
#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define has(s, e) s.count(e)

using namespace std;
using ll = long long;
using point = array<int, 2>;

int main() {
    speed;

    int N, W;
    cin >> N >> W;

    vector<int> w(N + 1), v(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> w[i] >> v[i];
    }

    int sum = accumulate(all(v), 0);

    vector<ll> dp(sum + 1, LLONG_MAX >> 1);

    dp[0] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = sum; j >= 0; j--) {
            if (j >= v[i]) {
                dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
            }
        }
    }

    do {
        if (dp[sum] <= W) {
            cout << sum;
            exit(0);
        }
    } while (sum--);
}
