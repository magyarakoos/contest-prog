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

const ll INF = 1e9, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    int N, C;
    cin >> N >> C;
    vector<int> a(N);
    for (int& x : a) cin >> x;
    int las = -INF, result = 0;
    for (int i = 0; i < N; i++) {
        if (las + C <= a[i]) {
            result++;
            las = a[i];
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