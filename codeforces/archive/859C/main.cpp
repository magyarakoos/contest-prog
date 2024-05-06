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
    vector<int> v(N), ss(N), dp(N);
    for (int& x : v) cin >> x;

    ss[N - 1] = v[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        ss[i] = ss[i + 1] + v[i];
    }

    dp[N - 1] = v[N - 1];

    for (int i = N - 2; i >= 0; i--) {
        dp[i] = max(
            v[i] + (ss[i + 1] - dp[i + 1]),
            dp[i + 1] - v[i]
        );
    }

    for (int i = 0; i < N; i++) {
        cout << dp[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < N; i++) {
        cout << ss[i] << " ";
    }
    cout << "\n";

    cout << dp[0] << " " << ss[0] - dp[0] << "\n";
}