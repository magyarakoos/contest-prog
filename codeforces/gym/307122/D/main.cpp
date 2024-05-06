#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

#define cases 0
void solve() {
    ll N, K, S;
    cin >> N >> K >> S;
    if ((N - 1) * K < S || K > S) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";

    ll pos = 1;
    for (int i = 0; i < S / K; i++) {
        if (pos == 1) {
            cout << N << " ";
            pos = N;
        } else {
            cout << "1 ";
            pos = 1;
        }
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
