#include <bits/stdc++.h>
using namespace std;

const string NAREK = "narek";
const int INF = 2e9;

void solve() {
    int N, M;
    cin >> N >> M;

    vector<string> s(N);
    for (int i = 0; i < N; i++) cin >> s[i];

    vector<int> dp(5, -INF);
    dp[0] = 0;

    for (int i = 0; i < N; i++) {
        auto ndp = dp;
        for (int j = 0; j < 5; j++) {
            if (dp[j] == -INF) continue;
            int score = 0, nxt = j;
            for (int k = 0; k < M; k++) {
                int pos = NAREK.find(s[i][k]);
                if (pos == -1) continue;
                if (nxt == pos) {
                    nxt = (nxt + 1) % 5;
                    score++;
                } else {
                    score--;
                }
            }

            ndp[nxt] = max(ndp[nxt], dp[j] + score);
        }

        dp = ndp;
    }

    int ans = 0;
    for (int i = 0; i < 5; i++)
        ans = max(ans, dp[i] - 2 * i);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
}
