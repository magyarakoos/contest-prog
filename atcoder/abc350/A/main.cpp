#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr bool cases = true;
void solve() {
    cout << "Hi mom\n";
}

#ifdef LOCAL
ifstream fin("../input");
ofstream fout("../output");
#define cin fin
#define cout fout
#endif
int main() {
    #ifndef LOCAl
    cin.tie(0), ios::sync_with_stdio(0);
    #endif
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}