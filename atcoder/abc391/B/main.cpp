#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    int N, M;
    cin >> N >> M;
    vector<string> S(N), T(M);
    for (string& x : S) cin >> x;
    for (string& x : T) cin >> x;
    for (int i = 0; i < N - M + 1; i++) {
        for (int j = 0; j < N - M + 1; j++) {
            auto ok = [&]() -> bool {
                for (int k = 0; k < M; k++) {
                    for (int l = 0; l < M; l++) {
                        if (T[k][l] != S[i + k][j + l])
                            return 0;
                    }
                }
                return 1;
            };
            if (ok()) {
                cout << i + 1 << " " << j + 1 << "\n";
                return;
            }
        }
    }
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
