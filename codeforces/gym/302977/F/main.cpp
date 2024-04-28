#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

constexpr ll INF = 1e18;

#define cases 0
void solve() {
    ll N, K;
    cin >> N >> K;
    cout << 
        1 + 
        (K >= 2) * N * (N - 1) / 2 +
        (K >= 3) * N * (N - 1) * (N - 2) / 3 + 
        (K >= 4) * N * (N - 1) * (N - 2) * (N - 3) * 9 / 24
    ;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
