#include <bits/stdc++.h>
#ifdef LOCAL
#include <magyarakoos-debug.h>
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

#define cases 0
void solve() {
    int N;
    cin >> N;
    vector<int> L(N), R(N);
    for (int i = 0; i < N; i++) cin >> L[i] >> R[i];

    ll sL = accumulate(all(L), 0LL), sR = accumulate(all(R), 0LL);

    if (sL <= 0 && sR >= 0) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
        return;
    }

    for (int i = 0; i < N; i++) {
        if (sR <= R[i] - L[i]) {
            R[i] -= sR;
            sR = 0;
            break;
        }
        sR -= R[i] - L[i];
        R[i] = L[i];
    }

    assert(sR == 0);

    for (int x : R) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
