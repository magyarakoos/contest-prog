#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) (int)v.size()

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
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