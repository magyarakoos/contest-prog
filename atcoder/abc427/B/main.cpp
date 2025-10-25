#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

int f(int x) {
    int a = 0;
    while (x) {
        a += x % 10;
        x /= 10;
    }
    return a;
}

#define cases 0
void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    a[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) { a[i] += f(a[j]); }
    }
    cout << a[n] << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
