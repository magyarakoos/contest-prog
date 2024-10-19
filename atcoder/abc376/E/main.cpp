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

const ll INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 1
void solve() {
    int N, K;
    cin >> N >> K;
    vector<array<int, 2>> a(N);
    for (int i = 0; i < N; i++) cin >> a[i][0];
    for (int i = 0; i < N; i++) cin >> a[i][1];
    sort(all(a));
    map<int, int> m;
    ll sum = 0;
    for (int i = 0; i < K - 1; i++) {
        sum += a[i][1];
        m[a[i][1]]++;
    }

    ll result = INF;

    for (int i = K - 1; i < N; i++) {
        int ao = a[i][1];
        sum += ao;
        result = min(result, a[i][0] * sum);

        m[ao]++;
        auto it = *m.rbegin();
        m[it.first]--;
        if (!m[it.first]) m.erase(it.first);
        sum -= it.first;
    }

    cout << result << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
