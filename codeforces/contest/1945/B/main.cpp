#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()

ifstream fin("../input");

#ifdef LOCAL
#define cin fin
#endif

void solve() {
    ll A, B, M;
    cin >> A >> B >> M;
    cout << M / A + M / B + 2 << "\n";
}

int main() {
    #ifndef LOCAl
    cin.tie(0);
    ios::sync_with_stdio(0);
    #endif
    int T;
    cin >> T;
    while (T--) solve();
}
