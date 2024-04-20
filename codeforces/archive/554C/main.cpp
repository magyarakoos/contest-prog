#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MOD = 1e9 + 7, MAXN = 1000;

ll choose[MAXN + 1][MAXN + 1];
int main() {
	cin.tie(0), ios::sync_with_stdio(0);

    for (int i = 0; i <= MAXN; i++) {
        for (int j = 0; j <= min(i, MAXN); j++) {
            if (j == 0 || i == j) {
                choose[i][j] = 1;
            } else {
                choose[i][j] = (choose[i - 1][j - 1] + choose[i - 1][j]) % MOD;
            }
        }
    }

    ll K, sum = 0, res = 1;
    cin >> K;
    
    for (int i = 0; i < K; i++) {
        ll c; cin >> c;

        sum += c;
        res *= choose[sum - 1][c - 1];
        res %= MOD;
    }

    cout << res;
}
