#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

#define cases 0
void solve() {
    string s;
    cin >> s;
    bool hasH = 0, hasV = 0;
    for (char c : s) {
        if (c == '1') {
            if (hasV) {
                cout << "3 1\n";
                hasV = 0;
            } else {
                cout << "1 1\n";
                hasV = 1;
            }
        } else {

        }
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
