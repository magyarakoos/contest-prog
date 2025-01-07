#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e9;

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int N;
    cin >> N;
    vector<array<int, 2>> a(N);
    for (int i = 0; i < N; i++) cin >> a[i][1];
    for (int i = 0; i < N; i++) cin >> a[i][0];
    sort(a.begin(), a.end());

    vector<array<int, 2>> dp(N, INF);
}
