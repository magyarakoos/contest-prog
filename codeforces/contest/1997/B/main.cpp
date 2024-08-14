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
    string a, b;
    cin >> a >> b;
    int result = 0;
    for (int i = 2; i < N; i++) {
        result += (a[i - 2] == '.' && a[i - 1] == '.' && a[i] == '.' &&
                   b[i - 2] == 'x' && b[i - 1] == '.' && b[i] == 'x') ||
                  (a[i - 2] == 'x' && a[i - 1] == '.' && a[i] == 'x' &&
                   b[i - 2] == '.' && b[i - 1] == '.' && b[i] == '.');
    }
    cout << result << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
