#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);

    for (int& x : A) cin >> x;

    vector<vector<int>> dp(N, vector<int>(N));

    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            if (i != j) {
                dp[i][j] = dp[i - 1][j - 1] + (A[i] == A[j]);
            }
        }
    }

    int maxx = 0, maxy = 0;
    for (int i = 0; i < N; i++) {
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
    } while (dp[maxy][maxx]);

    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] << ' ';
    }
}
