#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

#define cases 0
void solve() {
    int N, K;
    string s;
    cin >> N >> K >> s;
    vector<bool> v(27);
    while (K--) {
        char c;
        cin >> c;
        v[c - 'a'] = 1;
    }
    ll res = 0, curr = 0;
    s += 'a' + 26;
    for (char c : s) {
        if (v[c - 'a']) {
            curr++;
        } else if (curr) {
            res += curr * (curr + 1) / 2;
            curr = 0;
        }
    }
    cout << res;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
