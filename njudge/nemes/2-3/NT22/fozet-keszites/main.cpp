// huge if works
#pragma GCC optimize("Ofast,unroll-loops")

// got inspired by the submission of peti1234
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    vector dp(501, vector<int>(501));
    for (int i = 1; i < 32; i++) {
        for (int j = 1; j < 32; j++) {
            if ((i > 10 && j > 10) || gcd(i, j) > 1)
                continue;
            for (int k = 500; k >= i; k--) {
                for (int l = 500; l >= j; l--) {
                    dp[k][l] =
                        max(dp[k][l], dp[k - i][l - j] + 1);
                }
            }
        }
    }

    int T;
    cin >> T;
    while (T--) {
        int A, B;
        cin >> A >> B;
        cout << dp[A][B] << "\n";
    }
}
