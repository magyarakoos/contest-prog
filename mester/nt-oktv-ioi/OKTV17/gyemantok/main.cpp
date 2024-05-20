#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;
    
    vector<ll> dp(N + 1);
    dp[0] = 1;

    for (int i = N; i >= 1; i--) {
        for (int j = N; j >= i; j--) {
            dp[i] += dp[j];
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << dp[i] << " ";
    }
    cout << "\n";
}