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
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

const int INF = 2e9, MAXN = 1e4, MOD = 1e9 + 7;

#define cases 1
void solve() {
    int N;
    cin >> N;
    string s;
    vector<array<int, 2>> result;
    for (int i = 0; i < 6; i++) {
        s += to_string(N);
    }

    int len_n;
    if (N < 10)
        len_n = 1;
    else if (N < 100)
        len_n = 2;
    else
        len_n = 3;

    for (int a = 1; a <= MAXN; a++) {
        for (int b = max(1, len_n * a - 6);
             b <= min({MAXN, len_n * a - 1, N * a}); b++) {
            if (N * a - b == stoi(s.substr(0, len_n * a - b))) {
                result.push_back({a, b});
            }
        }
    }

    cout << result.size() << "\n";
    for (auto [a, b] : result) cout << a << " " << b << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
