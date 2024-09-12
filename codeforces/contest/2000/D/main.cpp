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
    int N;
    cin >> N;
    vector<ll> a(N), ps(N + 1);
    for (ll& x : a) cin >> x;
    string s;
    cin >> s;
    partial_sum(all(a), ps.begin() + 1);

    ll result = 0;
    int l = 0, r = N - 1;
    while (l < r) {
        if (s[l] == 'L' && s[r] == 'R') {
            result += ps[r + 1] - ps[l];
            l++;
            r--;
            continue;
        }
        if (s[l] != 'L') while (++l < N && s[l] != 'L');
        if (s[r] != 'R') while (--r >= 0 && s[r] != 'R');
    }

    cout << result << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
