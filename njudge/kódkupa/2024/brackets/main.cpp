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

    vector dp(N, vector<bool>(MAXM)),
        pathS(N, vector<bool>(MAXM));

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < MAXM; j++) {
            if (j + a[i] < MAXM && dp[i - 1][j + a[i]]) {
                dp[i][j] = 1;
                pathS[i][j] = j + a[i];
            }
            if (j - a[i] >= 0 && dp[i - 1][j - a[i]]) {
                dp[i][j] = 1;
                pathS[i][j] = j - a[i];
            }
        }
    }

    // for (int i = 0; i < N; i++) {
    //     cout << i << ":\n";
    //     for (auto [k, v] : pathS[i]) {
    //         cout << k << " " << v << "\n";
    //     }
    //     cout << "\n";
    // }

    for (int x : s) {
        if (!x) {
            vector<int> result(N);
            for (int i = N - 1; i >= 0; i--) {
                result[i] = x - pathS[i][x];
                x = pathS[i][x];
            }

            for (int x : result) {
                cout << string(abs(x), "()"[x < 0]);
            }
            cout << "\n";

            exit(0);
        }
    }

    cout << "-1\n";
}
