#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int dp[36][36];
bool vis[36][36];

int f(int n, int h) {
    if (vis[n][h]) return dp[n][h];
    vis[n][h] = 1;

    int result = 0;
    if (!h) {
        result = !n;
    } else if (h == 1) {
        result = n == 1;
    } else if (n == 1) {
        result = h == 1;
    } else {
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < h; j++) {
                result += f(i - 1, h - 1) * f(n - i, j);
                if (j + 1 < h) {
                    result += f(i - 1, j) * f(n - i, h - 1);
                }
            }
        }
    }

    return dp[n][h] = result;
}

int32_t main() {
    int n, h, result = 0;
    cin >> n >> h;
    while (h <= n) result += f(n, h++);
    cout << result;
}
