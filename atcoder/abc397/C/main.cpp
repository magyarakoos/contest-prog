#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int INF = 1e18, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 0
void solve() {
    int N;
    cin >> N;
    vector<int> a(N), b(N), h(N);
    for (int& x : a) {
        cin >> x;
        x--;
        h[x]++;
    }
    int right = 0, left = 0, result = 0;
    for (int x : h) right += x > 0;
    for (int i = 1; i < N; i++) {
        b[a[i - 1]]++;
        if (b[a[i - 1]] == h[a[i - 1]]) right--;
        if (b[a[i - 1]] == 1) left++;
        result = max(result, right + left);
    }
    cout << result << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
