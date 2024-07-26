#include <bits/stdc++.h>
#ifdef LOCAL
#include <magyarakoos-debug.h>
#else
#define DB(...)
#endif
using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) (int)v.size()
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

const ll INF = 2e9, MAXN = 2e5, MOD = 1e9 + 7;

int fact(int x) { return x <= 1 ? 1 : fact(x - 1) * x; }

#define cases 1
void solve() {
    int N, X;
    cin >> N >> X;

    ll result = 0;

    for (int a = 1; a <= N - 2; a++) {
        for (int b = 1; b <= N / a; b++) {
            // ab + ac + bc <= N => ab + c(a + b) <= N => c <= (N - ab) / (a +
            // b) a + b + c <= X => c <= X - (a + b)
            result += max(0, min((N - a * b) / (a + b), X - (a + b)));
        }
    }

    cout << result << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
