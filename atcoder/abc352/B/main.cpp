#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

#define cases 0
void solve() {
    string s, t;
    cin >> s >> t;
    int i = 0, j = 0;
    int N = sz(s);
    while (i < N) {
        if (s[i] == t[j]) {
            cout << j + 1 << " ";
            i++;
            j++;
        }
        else {
            j++;
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
