#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 500;

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, Q;
    cin >> N >> Q;

    vector<int> a(N);
    for (int& x : a) cin >> x;

    // transition: maximal profit where dp[i][j] (i < j)
    // means a pair (V, E)
    vector dp(MAXN + 1, vector<int>(MAXN + 1));
    for (int V = 1; V <= 500; V++) {}
}
