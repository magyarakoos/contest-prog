#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> A(N + 1), B(N + 1), F(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> A[i] >> B[i] >> F[i];
    }

    vector<int> dp(M + 1), last(M + 1);

    for (int i = 1; i <= M; i++) {
        dp[i] = dp[i - 1];
        last[i] = last[i - 1];
        for (int j = 1; j <= N; j++) {
            if (B[j] == i && dp[i] < dp[A[j] - 1] + F[j]) {
                dp[i] = dp[A[j] - 1] + F[j];
                last[i] = j;
            }
        }
    }

    cout << dp[M] << '\n';

    int curr = M;
    while (last[curr]) {
        cout << last[curr] << ' ';
        curr = A[last[curr]] - 1;
    }

    cout << endl;
}
