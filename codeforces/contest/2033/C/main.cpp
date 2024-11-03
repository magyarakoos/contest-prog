#include <bits/stdc++.h>
#ifdef LOCAL
#include <debug.h>
#else
#define DB(...)
#endif

using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) (int)v.size()

const ll INF = 2e9, MAXN = 2e5, MOD = 1e9 + 7;

#define cases 1
void solve() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int& x : a) cin >> x;
    vector<array<int, 2>> ch(N / 2);
    vector<int> dp(N / 2);

    for (int i = 0; i < N / 2; i++) {
        ch[i] = {a[i], a[N - i - 1]};
    }

    for (int i = 1; i < N / 2; i++) {
        int costnsw = (ch[i - 1][0] == ch[i][0]) +
                      (ch[i - 1][1] == ch[i][1]);
        int costsw = (ch[i - 1][1] == ch[i][0]) +
                     (ch[i - 1][0] == ch[i][1]);

        dp[i] = dp[i - 1] + min(costnsw, costsw);
    }

    if (N & 1) {
        cout << dp.back() + (ch[N / 2 - 1][0] == a[N / 2]) +
                    (ch[N / 2 - 1][1] == a[N / 2])
             << "\n";
    } else {
        cout << dp.back() +
                    (ch[N / 2 - 1][0] == ch[N / 2 - 1][1])
             << "\n";
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
