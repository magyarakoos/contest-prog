#include <bits/stdc++.h>
using namespace std;

const int MAXN = 501;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 25; j++) {
            if (gcd(i, j) != 1) continue;
            for (int k = i; k < MAXN; k++) {
                for (int l = j; l < MAXN; l++) {
                    dp[k][l] =
                        max(dp[k][l], dp[k - i][l - j] + 1);
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
    cout << dp[A][B] << "\n";
}
}
