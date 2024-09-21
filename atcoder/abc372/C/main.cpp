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

#define cases 0
void solve() {
    int N, Q;
    string s;
    cin >> N >> Q >> s;
    int result = 0;
    for (int i = 2; i < N; i++) {
        result += s[i - 2] == 'A' && s[i - 1] == 'B' && s[i] == 'C';
    }

    auto hasabc = [&](int i) -> bool {
        if (i >= 2 && s[i - 2] == 'A' && s[i - 1] == 'B' && s[i] == 'C')
            return 1;
        if (i >= 1 && i + 1 < N && s[i - 1] == 'A' && s[i] == 'B' &&
            s[i + 1] == 'C')
            return 1;
        if (i + 2 < N && s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C')
            return 1;
        return 0;
    };

    while (Q--) {
        int X;
        char C;
        cin >> X >> C;
        X--;

        if (hasabc(X)) result--;
        s[X] = C;
        if (hasabc(X)) result++;

        cout << result << "\n";
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
