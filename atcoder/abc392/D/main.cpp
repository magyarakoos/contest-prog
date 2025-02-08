#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 1e5 + 5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    int N;
    cin >> N;
    vector<vector<int>> dice(N);
    for (int i = 0; i < N; i++) {
        int K, A;
        cin >> K;
        while (K--) {
            cin >> A;
            dice[i].push_back(A);
        }
    }
    vector<vector<int>> dbS(N, vector<int>(MAXN));
    double result = 0;
    for (int i = 0; i < N; i++) {
        for (int x : dice[i]) dbS[i][x]++;
        for (int j = 0; j < i; j++) {
            double curr = 0;
            for (int k = 1; k < MAXN; k++) {
                curr += dbS[i][k] * dbS[j][k] /
                        (double)(dice[i].size() *
                                 dice[j].size());
            }
            result = max(result, curr);
        }
    }
    cout << fixed << setprecision(15) << result << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
