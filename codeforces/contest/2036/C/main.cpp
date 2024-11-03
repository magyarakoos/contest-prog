#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

#define cases 1
void solve() {
    string S;
    cin >> S;
    int N = S.size();
    vector<bool> v(N);
    for (int i = 0; i < N; i++) { v[i] = S[i] == '1'; }

    auto good = [](array<int, 4> a) -> bool {
        return a[0] && a[1] && !a[2] && !a[3];
    };

    set<int> goodS;
    vector<array<int, 4>> winS;
    for (int i = 3; i < N; i++) {
        winS.push_back(
            {v[i - 3], v[i - 2], v[i - 1], v[i]});
        if (good(winS.back())) { goodS.insert(i - 3); }
    }

    // DB(winS);
    int M = winS.size();

    int Q;
    cin >> Q;
    while (Q--) {
        int i, val;
        cin >> i >> val;
        i--;
        for (int j = -3; j <= 0; j++) {
            if (i + j < 0 || i + j >= M) continue;
            winS[i + j][-j] = val;
            if (good(winS[i + j])) {
                goodS.insert(i + j);
            } else {
                goodS.erase(i + j);
            }
        }
        if (!goodS.empty()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
