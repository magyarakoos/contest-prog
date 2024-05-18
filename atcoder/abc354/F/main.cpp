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

pair<vector<int>, int> cnt_before(const vector<int>& v, int N) {
    vector<int> res(N);
    vector<int> pileS;
    for (int i = 0; i < N; i++) {
        res[i] = lower_bound(pileS.begin(), pileS.end(), v[i]) - pileS.begin();
        if (res[i] == sz(pileS)) {
            pileS.push_back(v[i]);
        } else {
            pileS[res[i]] = v[i];
        }
    }
    return {res, sz(pileS)};
}

#define cases 1
void solve() {
    int N;
    cin >> N;
    vector<int> v(N);
    for (int& x : v) cin >> x;

    auto [A, len] = cnt_before(v, N);
    
    reverse(all(v));
    for (int& x : v) x = -x;
    
    auto [B, _] = cnt_before(v, N);
    reverse(all(B));
    
    vector<int> res;
    
    for (int i = 0; i < N; i++) {
        if (A[i] + B[i] + 1 == len) {
            res.push_back(i);
        }
    }
    cout << sz(res) << "\n";
    for (int x : res) cout << x + 1 << " ";
    cout << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}