#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MOD = 1e9 + 7, MAXN = 1001;

int choose[MAXN][MAXN];
int main() {
	cin.tie(0), ios::sync_with_stdio(0);

    for (int i = 0; i <= MAXN; i++) {
        for (int j = 0; j <= min(i, MAXN); j++) {
            if (j == 0 || i == j) {
                choose[i][j] = 1;
            } else {
                choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j];
            }
        }
    }

    int K, sum = 0;
    cin >> K;
    vector<int> dp(K);
    dp[1] = 1;

    for (int i = 1; i < K; i++) {
        int c;
        cin >> c;
        sum += c;
        dp[i] = choose[sum - 1][c - 1];
    }
}
