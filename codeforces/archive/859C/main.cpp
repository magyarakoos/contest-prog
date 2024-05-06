#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> v(N), dp(N);
    for (int& x : v) cin >> x;

    dp[N - 1] = v[N - 1];
    int suffix_sum = v[N - 1];

    for (int i = N - 2; i >= 0; i--) {
        dp[i] = max(
            dp[i + 1],
            v[i] + suffix_sum - dp[i + 1]
        );
        suffix_sum += v[i];
    }

    cout << suffix_sum - dp[0] << " " << "\n";
}
