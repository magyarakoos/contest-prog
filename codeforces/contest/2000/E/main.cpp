#include <bits/stdc++.h>
#ifdef LOCAL
#include <debug.h>
#else
#define DB(...)
#endif

using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) (int)v.size()

const ll INF = 2e9, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 1
void solve() {
    int N, M, K, W;
    cin >> N >> M >> K >> W;
    vector<ll> a(W);
    for (ll& x : a) cin >> x;

    vector<int> b(N * M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            b[i * M + j] = 
                (K - max(0, (K - 1) - j) - max(0, (K - 1) - (M - j - 1))) *
                (K - max(0, (K - 1) - i) - max(0, (K - 1) - (N - i - 1)));
        }
    }

    sort(rall(b));
    sort(rall(a));

    ll result = 0;

    for (int i = 0; i < W; i++) {
        result += a[i] * b[i];
    }

    cout << result << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
