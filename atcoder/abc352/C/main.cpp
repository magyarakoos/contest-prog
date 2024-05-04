#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

#define cases 0
void solve() {
    int N;
    cin >> N;
    vector<array<int, 2>> v(N);
    ll sum = 0;
    for (auto& [sh, h] : v) {
        cin >> sh >> h;
        sum += sh;
    }
    ll res = 0;
    for (auto [sh, h] : v) {
        smax(res, sum - sh + h);
    }
    cout << res;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
