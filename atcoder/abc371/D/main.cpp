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

#define cases 0
void solve() {
    int N;
    cin >> N;
    set<int> s;
    vector<ll> X(N), P(N);
    for (ll& x : X) cin >> x, s.insert(x);
    for (ll& x : P) cin >> x;

    vector<ll> ps(N + 1);
    partial_sum(all(P), ps.begin() + 1);

    int Q;
    cin >> Q;
    while (Q--) {
        int L, R;
        cin >> L >> R;
        auto itl = lower_bound(all(X), L);
        auto itr = lower_bound(all(X), R);
        if (!s.count(R)) itr--;

        cout << ps[(itr - X.begin()) + 1] - ps[(itl - X.begin())] << "\n";
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
