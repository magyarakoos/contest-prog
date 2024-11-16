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

const ll INF = 2e9, MAXN = 2e5, MOD = 1e9 + 7;

map<char, int> dx{{'E', 1}, {'W', -1}},
    dy{{'N', 1}, {'S', -1}};

#define cases 1
void solve() {
    int N;
    string s;
    cin >> N >> s;
    int x = 0, y = 0;

    for (int i = 0; i < N; i++) {
        x += dx[s[i]];
        y += dy[s[i]];
    }

    if (x % 2 || y % 2 || (!x && !y && N == 2)) {
        cout << "NO\n";
        return;
    }

    x /= 2;
    y /= 2;

    cout << "R";
    x -= dx[s[0]];
    y -= dy[s[0]];

    for (int i = 1; i < N; i++) {
        if (abs(x - dx[s[i]]) < abs(x) ||
            abs(y - dy[s[i]]) < abs(y)) {
            cout << "R";
            x -= dx[s[i]];
            y -= dy[s[i]];
        } else {
            cout << "H";
        }
    }

    cout << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
