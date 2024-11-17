#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define cases 1
void solve() {
    int K;
    cin >> K;
    vector<int> A(K);
    map<int, int> m;
    for (int& x : A) {
        cin >> x;
        m[x]++;
    }
    for (auto [key, val] : m) {
        // x * key = K - 2
        // (K - 2) / key = x
        if ((K - 2) % key) continue;
        int x = (K - 2) / key;
        if (x == key) {
            if (val >= 2) {
                cout << x << " " << x << "\n";
                return;
            }
        } else {
            if (m[x]) {
                cout << key << " " << x << "\n";
                return;
            }
        }
    }
    assert(0);
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
