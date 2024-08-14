#include <bits/stdc++.h>
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
    int N, K;
    cin >> N >> K;
    vector<int> v(N);
    for (int& e : v) cin >> e;
    int curr = 0, res = 0;
    for (int e : v) {
        if (curr + e > K) {
            res++;
            curr = 0;
        }
        curr += e;
    }
    cout << res + (bool)curr;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
