#include <algorithm>
#include <climits>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;

    vector<ll> a(N);
    for (ll& x : a) cin >> x;

    vector dp(N, vector<ll>(N));

    for (int l = N - 1; ~l; l--) {
        for (int r = l; r < N; r++) {
            if (l == r) {
                dp[l][r] = a[l];
            } else {
                dp[l][r] = max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);
            }
        }
    }

    cout << (accumulate(a.begin(), a.end(), 0LL) - dp[0][N - 1]) / 2 + dp[0][N - 1] << "\n";
}
