#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()

ifstream fin("../input");

#ifdef LOCAL
#define cin fin
#endif

void solve() {
    int A, B, C;
    cin >> A >> B >> C;
    if (B % 3 == 0) {
        cout << A + B / 3 + C / 3 + (bool)(C % 3) << "\n";
    }
    else if (3 - (B % 3) <= C) {
        A += B / 3 + (bool)(B % 3);
        C -= 3 - (B % 3);
        cout << A + C / 3 + (bool)(C % 3) << "\n";
    } else {
        cout << "-1\n";
    }
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
