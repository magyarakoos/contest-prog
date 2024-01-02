#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)
#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define has(s, e) s.count(e)

using namespace std;
using ll = long long;
using point = array<int, 2>;

int N, A, B, C;
vector<array<int, 3>> dp;

int valid_max(int curr) {
    int result = -1;
    for (int x : dp[curr]) {
        if (x != 0) {
            result = max(result, x);
        }
    }
    return result;
}

int main() {
    speed;

    cin >> N >> A >> B >> C;

    dp.resize(N + 1);

    if (A <= N) dp[A][0] = 1;
    if (B <= N) dp[B][1] = 1;
    if (C <= N) dp[C][2] = 1;

    for (int i = 1; i <= N; i++) {
        dp[i][0] = max((i >= A ? valid_max(i - A) + 1 : dp[i - 1][0]), dp[i][0]);
        dp[i][1] = max((i >= B ? valid_max(i - B) + 1 : dp[i - 1][1]), dp[i][1]);
        dp[i][2] = max((i >= C ? valid_max(i - C) + 1 : dp[i - 1][2]), dp[i][2]);
    }
/*
    for (int i = 1; i <= N; i++) {cout << dp[i][0] << ' ';} cout << '\n';
    for (int i = 1; i <= N; i++) {cout << dp[i][1] << ' ';} cout << '\n';
    for (int i = 1; i <= N; i++) {cout << dp[i][2] << ' ';} cout << '\n';
*/
    cout << *max_element(all(dp[N]));
}
