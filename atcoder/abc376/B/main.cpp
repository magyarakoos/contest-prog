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
    cin >> N >> Q;
    int lp = 0, rp = 1;
    auto betw = [&](int a, int b, int c) -> int {
        return a <= b && b <= c;
    };
    auto dist = [&](int a, int b, int o) -> int {
        if (a > b) swap(a, b);
        return betw(a, o, b) ? N - b + a : b - a;
    };
    int result = 0;
    while (Q--) {
        char H;
        int T;
        cin >> H >> T;
        T--;
        if (H == 'L') {
            result += dist(lp, T, rp);
            lp = T;
        } else {
            result += dist(rp, T, lp);

            rp = T;
        }
    }
    cout << result << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
