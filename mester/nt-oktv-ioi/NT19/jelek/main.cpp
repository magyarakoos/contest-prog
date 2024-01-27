#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);

    for (int& x : A) cin >> x;

    int H = N / 2 + (N & 1);

    vector<vector<int>> dp(2, vector<int>(N));

    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            dp[i][1] = (dp[i - 1][0] + 1);
        }
    }

    for (int i = 1; i < N; i++) {
        dp[i][1] = (dp[i - 1][0] + 1, 3);
    }

    int maxx = 0, maxy = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            if (dp[maxy][maxx] < dp[i][j]) {
                maxy = i;
                maxx = j;
            }
        }
    }

    vector<int> path;

    do {
        path.push_back(A[maxx]);
        maxx--;
        maxy--;
    } while (maxy >= 0 && maxx >= 0 && dp[maxy][maxx]);

    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] << ' ';
    }
}
