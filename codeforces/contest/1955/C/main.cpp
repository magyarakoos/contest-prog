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
    deque<ll> q;
    while (N--) {
        int X;
        cin >> X;
        q.push_back(X);
    }
    int res = 0;
    while (q.size() >= 2) {
        ll m = min(q.front(), q.back());
        if (K >= 2 * m) {
            res += 2;
            q.pop_front();
            q.pop_back();
        }
        else {
            int k = K;
            K -= min(q.front() + q.back(), K);
            q.back() -= k / 2;
            q.front() -= k / 2 + (k & 1);
        }
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
