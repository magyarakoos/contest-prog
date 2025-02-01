#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    int N, Q;
    cin >> N >> Q;
    map<int, int> nest, pig;
    for (int i = 0; i < N; i++) {
        nest[i + 1] = 1;
        pig[i + 1] = i + 1;
    }
    int result = 0;
    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int P, H;
            cin >> P >> H;
            nest[pig[P]]--;
            nest[H]++;
            if (nest[pig[P]] == 1) result--;
            if (nest[H] == 2) result++;
            // for (auto [k, v] : pig)
            //     cout << k << " " << v << "\n";
            // cout << "\n";
            // for (auto [k, v] : nest)
            //     cout << k << " " << v << "\n";
            pig[P] = H;
        } else {
            cout << result << "\n";
        }
    }
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
