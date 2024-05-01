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
    vector<int> v(N);
    for (int& x : v) cin >> x;
    int l = 0, r = N - 1;
    while (l < r) {
        
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
