#include <bits/stdc++.h>

using namespace std;

const string NAREK = "narek";

void solve() {
    int N, M;
    cin >> N >> M;
    vector<string> a(N);
    for (string& s : a) cin >> s;

    auto append = [&](int i,
                      array<int, 3> curr) -> array<int, 3> {
        for (char c : a[i]) {
            int pos = NAREK.find(c);
            if (pos != NAREK.npos) {
                if (curr[1] == pos) {
                    curr[0]++;
                    curr[0] %= 5;
                    curr[1]++;
                } else {
                    curr[2]++;
                }
            }
        }
        return curr;
    };

    auto score = [](array<int, 3> x) -> int {
        return x[0] - x[2];
    };

    vector<array<array<int, 3>, 2>> dp(N);
    dp[0][0] = {0, 0, 0};
    dp[0][1] = append(0, {0, 0, 0});

    for (int i = 1; i < N; i++) {
        dp[i][0] = dp[i - 1][score(dp[i - 1][0]) <
                             score(dp[i - 1][1])];
        auto ada = append(i, dp[i - 1][0]),
             adb = append(i, dp[i - 1][1]);
        dp[i][1] = (score(ada) < score(adb) ? adb : ada);
    }

    int result = 0;
    for (int i = 0; i < N; i++) {
        result =
            max({result, score(dp[i][0]), score(dp[i][1])});
    }

    cout << result << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}
