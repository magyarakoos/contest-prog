#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 501;
int dp[MAX_N][MAX_N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // Initialize dp array with INT_MAX
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            dp[i][j] = INT_MAX;
        }
    }

    // Base case
    dp[0][0] = 0;

    // Fill dp table
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 25; j++) {
            // Skip if gcd != 1
            if (__gcd(i, j) != 1) { continue; }

            for (int k = i; k < MAX_N; k++) {
                for (int l = j; l < MAX_N; l++) {
                    // Check if previous state is reachable
                    if (dp[k - i][l - j] != INT_MAX) {
                        dp[k][l] = min(
                            dp[k][l], dp[k - i][l - j] + 1);
                    }
                }
            }
        }
    }

    int T;
    cin >> T;

    while (T--) {
        int A, B;
        cin >> A >> B;

        // Check if solution exists
        if (dp[A][B] == INT_MAX) {
            cout << -1 << "\n";
        } else {
            cout << dp[A][B] << "\n";
        }
    }

    return 0;
}
