#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    int mn_i = -1, mx_i = -1;
    for (int i = 0; i < N; i++) {
        if (S[i] == '1') {
            if (mn_i == -1) mn_i = i;
            mx_i = i;
        }
    }
    int result = 0;
    vector<int> lcnt(N), rcnt(N);
    for (int i = mn_i; i <= mx_i; i++) {
        lcnt[i] = S[i] == '1';
        if (i) lcnt[i] += lcnt[i - 1];
    }
    for (int i = mx_i; i >= mn_i; i--) {
        rcnt[i] = S[i] == '1';
        if (i < mx_i) rcnt[i] += rcnt[i + 1];
    }
    for (int i = mn_i; i <= mx_i; i++) {
        result += (S[i] == '0') * min(lcnt[i], rcnt[i]);
    }
    cout << result << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
