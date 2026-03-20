#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MOD = 1e9 + 7, BMOD = 29;

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    int h = 0;
    for (int i = n - 1; ~i; i--) {
        h *= BMOD;
        h %= MOD;
        h += s[i] - 'a' + 1;
        h %= MOD;
        cout << h << " ";
    }
    cout << "\n";
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) solve();
}
