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

#define cases 0
void solve() {
    ll N;
    cin >> N;
    if (N == 1) {
        cout << "0\n";
        return;
    }

    ll x = N - 2;
    int i = 1, pw = 0;

    while (i < MAXN) {
        ll y = 9 * pow(10, pw);
        if (x - y < 0) {
            break;
        }
        x -= y;
        i++;
        if (i & 1) pw++;
    }

    string result = to_string(x);
    while (result.size() < pw + 1) {
        result = '0' + result;
    }
    result[0]++;
    for (int k = result.size() - 1 - (i & 1); ~k; k--) {
        result += result[k];
    }

    cout << result << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
