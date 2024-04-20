#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr bool cases = true;
void solve() {
    cout << "Hi mom\n";
}

#ifdef LOCAL
ifstream fin("../input");
#define cin fin
#endif
int main() {
    #ifndef LOCAL
    cin.tie(0), ios::sync_with_stdio(0);
    #endif
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}