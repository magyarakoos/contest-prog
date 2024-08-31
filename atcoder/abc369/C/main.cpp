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
    vector<int> a(N);
    for (int& x : a) cin >> x;
    ll result = N;
    ll l = 0, r = 1;
    while (r < N) {
        if (a[l + 1] - a[l] != a[r] - a[r - 1]) {
            DB("W", l, r - 1);
            result += (r - l) * (r - l - 1) / 2;
            r++;
            if (r < N) {
                while (l < r && a[l + 1] - a[l] != a[r] - a[r - 1]) l++;
            } else {
                l = r - 1;
            }
            if (l + 1 == r) result++;
        } else {
            if (r + 1 == N) { result += (r - l + 1) * (r - l) / 2; }
            r++;
        }
    }
    cout << result;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
