#include <cassert>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const int MAXM = 50005;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<int> a(N);
    for (int& x : a) cin >> x;

    vector dp(N, vector<bool>(MAXM));
    dp[0][a[0]] = 1;

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < MAXM; j++) {
            dp[i][j] =
                (j + a[i] < MAXM && dp[i - 1][j + a[i]]) ||
                (j - a[i] >= 0 && dp[i - 1][j - a[i]]);
        }
    }

    if (dp[N - 1][0]) {
        vector<int> result(N, -1);
        for (int i = N - 2, x = 0; i >= 0; i--) {
            if (x + a[i + 1] < MAXM &&
                dp[i][x + a[i + 1]]) {
                x += a[i + 1];
                result[i] = -1;
            } else {
                x -= a[i + 1];
                result[i] = 1;
            }
        }

        for (int x : result) cout << x << " ";
        cout << "\n";

        for (int x : result) {
            cout << string(abs(x), "()"[x < 0]);
        }
        cout << "\n";
    } else {
        cout << "-1\n";
    }
}
