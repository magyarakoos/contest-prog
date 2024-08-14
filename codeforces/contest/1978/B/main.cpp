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
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

const ll INF = 2e9, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 1
void solve() {
    ll N, A, B;
    cin >> N >> A >> B;
    if (B <= A) {
        cout << N * A << "\n";
        return;
    }
    ll d = B - A;
    if (d > N) {
        cout << B * (B + 1) / 2 - (B - N) * (B - N + 1) / 2 << "\n";
    } else {
        ll nn = B * (B + 1) / 2 - A * (A + 1) / 2;
        cout << nn + (N - d) * A << "\n";
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
