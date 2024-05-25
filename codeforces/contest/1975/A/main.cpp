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

int cut_point(const vector<int>& v, int N) {
    for (int i = 1; i < N; i++) {
        if (v[i - 1] > v[i]) return i - 1;
    }
    return N;
}

bool monoton(const vector<int>& v, int i, int N) {
    for (i++; i < N; i++) {
        if (v[i - 1] > v[i]) return 0;
    }
    return 1;
}

#define cases 1
void solve() {
    int N;
    cin >> N;
    vector<int> v(N);
    for (int& x : v) cin >> x;
    int cp = cut_point(v, N);
    if (cp == N) {
        cout << "YES\n";
        return;
    }
    cout << (v[0] >= v[N - 1] && monoton(v, cp + 1, N) ? "YES\n" : "NO\n");
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}