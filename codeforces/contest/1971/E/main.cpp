#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) (int)v.size()
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

const ll INF = 2e9, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 1
void solve() {
    int N, K, Q;
    cin >> N >> K >> Q;

    vector<int> A(K + 1), B(K + 1);
    for (int i = 1; i <= K; i++) cin >> A[i];
    for (int i = 1; i <= K; i++) cin >> B[i];

    while (Q--) {
        int D;
        cin >> D;

        int idx = lower_bound(all(A), D) - A.begin();
        if (D == A[idx]) {
            cout << B[idx] << " ";
            continue;
        }

        idx--;
        int res = B[idx];
        int delta_s = A[idx + 1] - A[idx];
        int delta_t = B[idx + 1] - B[idx];
        int velocity = delta_s / delta_t;
        cout << res + (D - A[idx]) * delta_t / delta_s << " ";
    }
    cout << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}