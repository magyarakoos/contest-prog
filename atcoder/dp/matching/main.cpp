#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

void madd(int& x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;

    vector can(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> can[i][j];
        }
    }

    vector<int> dp(1 << N);

    dp[0] = 1;

    for (int mask = 0; mask < (1 << N) - 1; mask++) {
        int a = __builtin_popcount(mask);
        for (int b = 0; b < N; b++) {
            if (can[a][b] && !(mask >> b & 1)) {
                madd(dp[mask ^ (1 << b)], dp[mask]);
            }
        }
    }

    cout << dp.back() << "\n";
}
