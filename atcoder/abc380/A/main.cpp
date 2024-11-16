#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

#define cases 0
void solve() {
    string S;
    cin >> S;
    sort(S.begin(), S.end());
    cout << (S == "122333" ? "Yes" : "No") << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
