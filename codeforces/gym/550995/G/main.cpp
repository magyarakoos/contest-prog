#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> a;
vector<vector<int>> dp;

int solve(int l, int r) {
    if (dp[l][r]) return dp[l][r];
    if (l == r) return 1;
    if (l > r) return 0;

    return dp[l][r] = max({(a[l] == a[r]) * (solve(l + 1, r - 1) + 2),
                           solve(l, r - 1), solve(l + 1, r)});
}

int main() {
    cin >> N;

    a.resize(N);
    dp.assign(N, vector<int>(N));
    for (int& x : a) cin >> x;

    cout << solve(0, N - 1) << "\n";
}
