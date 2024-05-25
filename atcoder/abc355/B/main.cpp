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
    int N, M;
    cin >> N >> M;
    set<int> aS;
    vector<int> v(N + M);
    for (int i = 0; i < N; i++) {
        int X;
        cin >> X;
        aS.insert(X);
        v[i] = X;
    }
    for (int i = 0; i < M; i++) {
        int X;
        cin >> X;
        v[i + N] = X;
    }
    sort(all(v));
    for (int i = 1; i < N + M; i++) {
        if (aS.count(v[i - 1]) && aS.count(v[i])) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}