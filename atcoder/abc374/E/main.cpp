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
    int N, X;
    cin >> N >> X;
    vector<int> a(N), p(N), b(N), q(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    auto fnd = [](int A, int P, int B, int Q, int w) -> ll {
        if (A * Q < B * P) {
            swap(A, B);
            swap(P, Q);
        }
        ll result = 1e18;
        for (ll incl = 0; incl < 200 && B * incl <= w; incl++) {
            ll rem = (w - B * incl);
            result = min(result,
                         Q * incl + (rem / A + (bool)(rem % A)) * P);
        }
        return result;
    };

    auto cost = [&](int w) -> ll {
        ll result = 0;
        for (int i = 0; i < N; i++) {
            result += fnd(a[i], p[i], b[i], q[i], w);
        }
        return result;
    };

    auto f = [&](int w) -> bool { return cost(w) > X; };

    int l = 0, r = 1e9 + 5;
    while (r - l > 1) {
        int m = (r + l) / 2;
        if (f(m)) {
            r = m;
        } else {
            l = m;
        }
    }

    cout << l;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
