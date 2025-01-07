#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e9;

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;

    cout << "RED N" << endl;

    vector<array<int, 2>> a(N + 1);
    for (int i = 1; i <= N; i++) cin >> a[i][1];
    for (int i = 1; i <= N; i++) cin >> a[i][0];
    sort(a.begin() + 1, a.end());

    vector<int> sideA(1), sideB(1);
    for (int i = 1; i <= N; i++) {
        (a[i][1] ? sideB : sideA).push_back(a[i][0]);
    }
    int M = sideA.size() - 1, K = sideB.size() - 1;

    vector dp(M + 1, vector<int>(K + 1, INF));
    dp[0][0] = 0;

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= K; j++) {
            int curr_k = 0;
            for (int k = i - 1; k >= 0; k--) {
                curr_k += sideA[i] - sideA[k];
                int curr_l = 0;
                for (int l = j - 1; l >= 0; l--) {
                    l += sideB[j] - sideB[l];
                    dp[i][j] =
                        min(dp[i][j],
                            dp[k][l] + curr_k + curr_l);
                }
            }
            cout << dp[i][j] << " " << flush;
        }
        cout << "\n";
    }
}
