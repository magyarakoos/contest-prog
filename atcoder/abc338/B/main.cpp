#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define cases 0
void solve() {
    string s;
    cin >> s;
    map<char, int> m;
    for (char c : s) m[c]++;
    int mx = 0;
    char mxc = '$';
    for (auto [k, v] : m) {
        if (mx < v) {
            mx = v;
            mxc = k;
        }
    }
    cout << mxc;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
