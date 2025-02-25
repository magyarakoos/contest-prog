#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 1
void solve() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int& x : a) cin >> x;
    array<int, 3> result = {0, -1, -1};
    for (int i = 0; i < N; i++) {
        int big = 0, smol = 0;
        for (int j = i; j < N; j++) {
            if (a[i] < a[j])
                big++;
            else if (a[i] > a[j])
                smol++;
            result = max(result, {smol - big, i, j});
        }
    }
    assert(result[1] >= 0);
    cout << result[1] + 1 << " " << result[2] + 1 << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
