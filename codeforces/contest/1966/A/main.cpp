#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

#define cases 1
void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> v(100);
    while (N--) {
        int X;
        cin >> X;
        v[X - 1]++;
    }
    while (1) {
        int mxi = max_element(all(v)) - v.begin();
        if (v[mxi] < K) break;
        v[mxi] -= K;
        int mxi2 = max_element(all(v)) - v.begin();
        v[mxi2] += K - 1;
    }
    cout << accumulate(all(v), 0) << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
