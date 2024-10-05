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
    int N, S, T;
    cin >> N >> S >> T;
    vector<array<array<int, 2>, 2>> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i][0][0] >> a[i][0][1] >> a[i][1][0] >> a[i][1][1];
    }

    auto f = [](array<int, 2> st, array<int, 2> en) -> double {
        double dx = abs(st[0] - en[0]);
        double dy = abs(st[1] - en[1]);
        return sqrt(pow(dx, 2) + pow(dy, 2));
    };

    double result = 1e15;
    vector<int> p(N);
    iota(all(p), 0);
    do {
        for (int mask = 0; mask < (1 << N); mask++) {
            array<int, 2> pos = {0, 0};
            double curr = 0;
            for (int i = 0; i < N; i++) {
                array<int, 2> ap = a[p[i]][0], bp = a[p[i]][1];
                if (mask >> i & 1) swap(ap, bp);
                curr += f(pos, ap) / S + f(ap, bp) / T;
                pos = bp;
            }
            result = min(result, curr);
        }
    } while (next_permutation(all(p)));
    cout << fixed << setprecision(15) << result << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}

