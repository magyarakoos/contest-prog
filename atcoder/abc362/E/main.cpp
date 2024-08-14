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

const ll INF = 2e9, MAXN = 2e5, MOD = 998244353;

void madd(ll& x, ll y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

#define cases 0
void solve() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int& x : a) cin >> x;

    if (N == 1) {
        cout << N << "\n";
        return;
    }

    vector<vector<map<int, ll>>> cache(N + 1, vector<map<int, ll>>(N));

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            cache[2][j][a[j] - a[i]]++;
        }
    }

    cout << N << " " << N * (N - 1) / 2 << " ";

    for (int i = 3; i <= N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < j; k++) {
                madd(cache[i][j][a[j] - a[k]], cache[i - 1][k][a[j] - a[k]]);
            }
        }

        ll curr = 0;
        for (int j = 0; j < N; j++) {
            for (auto [key, value] : cache[i][j]) {
                madd(curr, value);
            }
        }

        cout << curr << " ";
    }

    cout << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
