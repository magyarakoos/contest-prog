#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    int N;
    cin >> N;
    vector<int> ans;
    for (int i = 1; i <= N - N % 2 * 2; i += 2) {
        cout << i << " ";
    }
    if (N % 2 && N != 1) cout << N << " ";
    for (int i = N - !(N % 2) - N % 2 * 2; i >= 1; i -= 2) {
        cout << i << " ";
    }
    for (int i = 2; i <= N - !(N % 2) * 2; i += 2) {
        cout << i << " ";
    }
    if (!(N % 2 && N != 1)) cout << N << " ";
    for (int i = N - (N % 2) - !(N % 2) * 2; i >= 2;
         i -= 2) {
        cout << i << " ";
    }
    cout << N << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
