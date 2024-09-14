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

#define cases 0
void solve() {
    int N;
    cin >> N;
    vector<ll> A(N);
    for (ll& x : A) cin >> x;

    map<int, vector<ll>> m;
    for (int i = 0; i < N; i++) { m[A[i]].push_back(i); }

    ll result = 0;

    for (auto [k, v] : m) {
        for (int i = 0; i < sz(v); i++) {
            int j = i ? v[i - 1] + 1 : 0;
            result += (v[i] - j + 1) * ((N - 1) - v[i] + 1);
        }
    }

    cout << result;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
