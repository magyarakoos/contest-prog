#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

#define cases 1
void solve() {
    ll N, K;
    cin >> N >> K;
    vector v(N, 0LL);
    for (ll& x : v) cin >> x;

    int l = 0, r = N - 1, res = 0;
    while (l <= r) {
        assert(K >= 0);
        if (K == 0) break;
        if (l == r) {
            v[l] -= K;
            if (v[l] <= 0) res++;
            break;
        }
        if (v[l] == v[r]) {
            if (K >= v[l] * 2) {
                K -= v[l] * 2;
                res += 2;
                l++;
                r--;
                continue;
            }
            if (K + 1 == v[l] * 2) {
                res++;
            }
            break;
        }
        if (v[l] < v[r]) {
            if (K >= v[l] * 2) {
                K -= v[l] * 2;
                res++;
                l++;
                continue;
            }
            if (K + 1 == v[l] * 2) {
                res++;
            }
            break;
        }
        if (v[r] < v[l]) {
            if (K >= v[r] * 2) {
                K -= v[r] * 2;
                res++;
                r--;
                continue;
            }
            if (K + 1 == v[r] * 2) {
                res++;
            }
            break;
        }
        assert(0);
    }
    cout << res << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
