#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> a;
vector<vector<int>> dp;

int solve(int l, int r) {
    if (l == r) return 1;
    if (l > r) return 0;
    if (dp[l][r]) return dp[l][r];

    dp[l][r] = 1 + solve(l + 1, r);
    if (a[l] == a[l + 1]) {
        dp[l][r] = min(dp[l][r], 1 + solve(l + 2, r));
    }

    for (int m = l + 2; m <= r; m++) {
        if (a[l] == a[m]) {
            dp[l][r] =
                min(dp[l][r], solve(l + 1, m - 1) + solve(m + 1, r));
        }
    }

    return dp[l][r];
}

int main() {
    cin >> N;

    a.resize(N);
    dp.assign(N, vector<int>(N));
    for (int& x : a) cin >> x;

    cout << solve(0, N - 1) << "\n";
}
