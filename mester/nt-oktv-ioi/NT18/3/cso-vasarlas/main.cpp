#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

constexpr int INF = 1e9;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    vector<int> H(N), A(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i] >> A[i];
    }

    vector<int> dp(M + 1);
    vector<vector<int>> buyS(M + 1, vector<int>(N));

    for (int i = 1; i <= M; i++) {
        dp[i] = INF;
        for (int j = 0; j < N; j++) {
            if (i < H[j]) continue;

            if (dp[i] > dp[i - H[j]] + A[j]) {

                dp[i] = dp[i - H[j]] + A[j];
                buyS[i] = buyS[i - H[j]];
                buyS[i][j]++;
            }
        }
    }

    if (dp[M] == INF) {
        cout << 0;
        exit(0);
    }

    cout << dp[M] << '\n';

    for (int i = 0; i < N; i++) {
        
    }
}