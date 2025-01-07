#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e9;

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;

    vector<array<int, 2>> a(N + 1);
    for (int i = 1; i <= N; i++) cin >> a[i][1];
    for (int i = 1; i <= N; i++) cin >> a[i][0];
    sort(a.begin() + 1, a.end());

    vector<int> sideA, sideB;
    for (int i = 1; i <= N; i++) {
        (a[i][1] ? sideB : sideA).push_back(a[i][0]);
    }

    vector dp(N + 1, {INF, INF});
    dp[0] = {0, 0};

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < i; j++) {}
    }
}
