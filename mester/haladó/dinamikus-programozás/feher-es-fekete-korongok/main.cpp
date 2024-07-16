#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;

    vector<int> a(N);
    for (int& x : a) cin >> x;

    vector dp(N, vector<int>(N));

    for (int l = N - 2; ~l; l--) {
        for (int r = l; r < N; r++) {
            if (l == r) {
                dp[l][r] = a[l];
            } else {
                dp[l][r] = max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);
            }
        }
    }

    cout << (accumulate(a.begin(), a.end(), 0) - dp[0][N - 1]) / 2 + dp[0][N - 1] << "\n";
}
