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

bool pal(string s, int l, int r) {
    while (l < r) {
        if (s[l] != s[r]) return 0;
        l++, r--;
    }
    return 1;
}

#define cases 0
void solve() {
    int N, K;
    string s;
    cin >> N >> K >> s;
    int result = 0;
    sort(all(s));
    do {
        bool ok = 1;
        for (int i = 0; i <= N - K; i++) {
            if (pal(s, i, i + K - 1)) {
                ok = 0;
                break;
            }
        }
        result += ok;
    } while (next_permutation(all(s)));
    cout << result;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
