#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 2e9;

int main() {
    int N;
    cin >> N;

    vector<array<int, 2>> a(N + 1);
    for (int i = 1; i <= N; i++) cin >> a[i][1];
    for (int i = 1; i <= N; i++) cin >> a[i][0];
    sort(a.begin(), a.end());

    vector<int> dp(N + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= N; i++) {
        array<int, 2> cnt = {0, 0};
        int curr = 0;
        for (int j = i; j > 0; j--) {
            cnt[a[j][1]]++;
            curr += a[i][0] - a[j][0];
            if (cnt[0] && cnt[1] && dp[j - 1] != INF) {
                dp[i] = min(dp[i], dp[j - 1] + curr);
            }
        }
        cout << dp[i] << " ";
    }

    assert(dp[N] != INF);

    cout << dp[N] << "\n";
}
