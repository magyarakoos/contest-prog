#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

#define cases 0
void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> v(N), vv;
    for (int& x : v) cin >> x;
    vv = v;
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        vv[i] *= c == '1';
        v[i] *= c == '0';
    }
    vector<int> ps(N + 1);
    for (int i = 1; i <= N; i++) {
        ps[i] = ps[i - 1] + v[i - 1];
    }

    int res = 0;
    for (int i = K; i <= N; i++) {
        smax(res, ps[i] - ps[i - K]);
    }
    
    cout << res + accumulate(all(vv), 0);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
