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
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

const ll INF = 2e9, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 1
void solve() {
    int N, M;
    cin >> N >> M;
    array<int, 7> cnt = {0};
    while (N--) {
        char c;
        cin >> c;
        cnt[c - 'A']++;
    }
    int res = 0;
    for (int i = 0; i < 7; i++) {
        res += max(0, M - cnt[i]);
    }
    cout << res << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
