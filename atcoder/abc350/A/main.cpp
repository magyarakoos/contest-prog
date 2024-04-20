#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define cases 1
void solve() {
    cout << "Hi mom\n";
}

#ifdef LOCAL
#define cin fin
#define cout fout
ifstream fin("../input");
ofstream fout("../output");
#endif
int main() {
    #ifndef LOCAl
    cin.tie(0), ios::sync_with_stdio(0);
    #endif
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}