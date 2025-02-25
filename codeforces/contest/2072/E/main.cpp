#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 1
void solve() {
    int K;
    cin >> K;
    int x = 0, y = 1, row = 0;
    vector<array<int, 2>> result;
    while (K > 0) {
        if (K >= row) {
            x++;
            result.push_back({x, y});
            K -= row;
            row++;
        } else {
            row = 0;
            y++;
        }
    }
    cout << result.size() << "\n";
    for (auto [xi, yi] : result)
        cout << xi << " " << yi << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
