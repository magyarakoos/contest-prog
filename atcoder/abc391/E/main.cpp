#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

vector<vector<bool>> B;

#define pop __builtin_popcount

int solve(int i, int j) {
    if (i + 1 == B.size()) { return 1; }
    array<int, 3> a = {solve(i + 1, j * 3),
                       solve(i + 1, j * 3 + 1),
                       solve(i + 1, j * 3 + 2)};
    int curr = B[i + 1][j * 3] |
               (B[i + 1][j * 3 + 1] << 1) |
               (B[i + 1][j * 3 + 2] << 2);
    int result = INF;
    for (int bm = 0; bm < (1 << 3); bm++) {
        if ((pop(curr) >= 2 && pop(bm) <= 1) ||
            (pop(curr) <= 1 && pop(bm) >= 2)) {
            int cost = 0;
            for (int i = 0; i < 3; i++) {
                if ((bm >> i & 1) != (curr >> i & 1)) {
                    cost += a[i];
                }
            }
            result = min(result, cost);
        }
    }
    return result;
}

#define cases 0
void solve() {
    int N;
    cin >> N;
    int M = pow(3, N);
    B.assign(1, vector<bool>(M));
    for (int i = 0; i < M; i++) {
        char c;
        cin >> c;
        B[0][i] = c == '1';
    }
    auto apply = [](vector<bool> a) -> vector<bool> {
        vector<bool> result;
        for (int i = 2; i < a.size(); i += 3) {
            sort(a.begin() + i - 2, a.begin() + i + 1);
            result.push_back(a[i - 1]);
        }
        return result;
    };
    for (int i = 0; i < N; i++) {
        B.push_back(apply(B.back()));
    }
    // for (int i = 0; i <= N; i++) {
    //     for (int x : B[i]) cout << x << " ";
    //     cout << "\n";
    // }
    reverse(B.begin(), B.end());
    cout << solve(0, 0);
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
