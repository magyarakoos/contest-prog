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
    ll N, K;
    cin >> N >> K;
    N %= MOD;

    if (K == 1) {
        cout << N << "\n";
        return;
    }

    ll a = 1, b = 1;
    int i = 2;
    while (1) {
        ll tmp = a;
        a = b;
        b = tmp + b;
        if (b % K == 0) { break; }
        a %= K;
        b %= K;
        i++;
    }

    cout << (N * (i + 1)) % MOD << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
