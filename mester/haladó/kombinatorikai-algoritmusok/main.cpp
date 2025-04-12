#include <bits/stdc++.h>
using namespace std;
#define int int64_t

vector<int> dp(33, -1);
int F(int n) {
    if (n == 1) return 1;
    if (dp[n] != -1) return dp[n];
    int result = 0;
    for (int i = 1; i < n; i++) {
        result += F(i) * F(n - i);
    }
    return dp[n] = result;
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    cout << F(n) << "\n";
}
