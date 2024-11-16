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

const ll INF = 4e11, MAXN = 2e5, MOD = 1e9 + 7;

bool can(const vector<int>& A, const vector<int>& C, ll H,
         int N, ll M) {
    ll damage = 0;
    for (int i = 0; i < N; i++) {
        damage += A[i] * (M / C[i] + 1);
        if (damage >= H) return 1;
    }
    return 0;
}

#define cases 1
void solve() {
    int H, N;
    cin >> H >> N;
    vector<int> A(N), C(N);
    for (int& x : A) cin >> x;
    for (int& x : C) cin >> x;

    ll low = 0, high = INF;
    while (low < high) {
        ll mid = low + (high - low) / 2;
        if (can(A, C, H, N, mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << low + 1 << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
