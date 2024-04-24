#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 1e5;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, T, H;
    cin >> N >> T >> H;
    vector<array<int, 2>> v(N + 2);
    for (int i = 1; i <= N; i++) {
        cin >> v[i][0] >> v[i][1];
    }
    v[N + 1] = {T, 0};

    vector<array<int, 2>> dp(N + 2, INF);
    dp[0] = {0, 0};

    for (int i = 2; i <= N + 1; i++) {

    }
}