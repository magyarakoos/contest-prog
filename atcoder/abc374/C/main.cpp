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
    vector<int> K(N);
    int sum = 0;
    for (int& x : K) cin >> x, sum += x;
    int result = 2e9 + 5;
    for (int mask = 0; mask < (1 << N); mask++) {
        int asum = 0;
        for (int i = 0; i < N; i++) {
            if (mask >> i & 1) asum += K[i];
        }
        result = min(result, max(asum, sum - asum));
    }
    cout << result << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
