#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    string S;
    cin >> S;
    int j = 0;
    int result = 0;
    for (int i = 0; i < S.size(); i++) {
        bool b = S[i] == 'o';
        if (j % 2 == b) {
            j++;
        } else {
            j += 2;
            result++;
        }
    }
    cout << result + (j % 2) << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
