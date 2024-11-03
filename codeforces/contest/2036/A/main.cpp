#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

#define cases 1
void solve() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int& x : a) cin >> x;
    for (int i = 1; i < N; i++) {
        if (abs(a[i - 1] - a[i]) != 5 &&
            abs(a[i - 1] - a[i]) != 7) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
