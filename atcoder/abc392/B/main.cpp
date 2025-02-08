#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    int N, M;
    cin >> N >> M;
    set<int> A;
    while (M--) {
        int X;
        cin >> X;
        A.insert(X);
    }
    vector<int> result;
    for (int i = 1; i <= N; i++) {
        if (!A.count(i)) { result.push_back(i); }
    }
    cout << result.size() << "\n";
    for (int x : result) cout << x << " ";
    cout << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
