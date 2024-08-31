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
    vector<int> a(N);
    vector<char> s(N);
    for (int i = 0; i < N; i++) { cin >> a[i] >> s[i]; }
    int lp = -1, rp = -1;
    ll result = 0;
    for (int i = 0; i < N; i++) {
        if (s[i] == 'L') {
            if (lp != -1) { result += abs(a[i] - lp); }
            lp = a[i];
        }
        if (s[i] == 'R') {
            if (rp != -1) { result += abs(a[i] - rp); }
            rp = a[i];
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
