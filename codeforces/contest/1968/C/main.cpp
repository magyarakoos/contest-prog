#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

const ll INF = 1e18;

vector<ll> v;
ll N, K;

ll check(ll x) {
    ll cost = 0;
    for (ll y : v) {
        if (y < x) {
            cost += x - y;
        }
    }
    return cost;
}

#define cases 1
void solve() {
    cin >> N >> K;
    v.assign(N, 0);
    ll mn = INF;
    for (ll& x : v) {
        cin >> x;
        smin(mn, x);
    }

    ll left = mn, right = mn + K + 1;
    while (right - left > 1) {
        ll mid = (left + right) / 2;
        if (check(mid) <= K) {
            left = mid;
        } else {
            right = mid;
        }
    }
    ll res = left + (N - 1) * (left - 1) + 
        (K - check(left)) + 
        count_if(all(v), [&](ll x){ return x >= left + 1; });
    
    cout << res << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
