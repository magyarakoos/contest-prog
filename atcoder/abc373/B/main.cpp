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
    map<char, int> m;
    for (int i = 0; i < 26; i++) {
        char c;
        cin >> c;
        m[c] = i;
    }
    string al;
    for (int i = 0; i < 26; i++) al += 'A' + i;
    DB(al);

    int result = 0;
    for (int i = 1; i < 26; i++) {
        result += abs(m[al[i - 1]] - m[al[i]]);
    }
    cout << result;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
