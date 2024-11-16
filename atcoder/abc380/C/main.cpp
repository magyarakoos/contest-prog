#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

#define cases 0
void solve() {
    int N, K;
    string S;
    cin >> N >> K >> S;
    vector<array<int, 2>> a;
    for (char c : S) {
        if (c == '0') {
            if (a.empty() || a.back()[0]) {
                a.push_back({0, 1});
            } else {
                a.back()[1]++;
            }
        } else {
            if (a.empty() || !a.back()[0]) {
                a.push_back({1, 1});
            } else {
                a.back()[1]++;
            }
        }
    }

    int ko, kmoo, j = 0;
    for (int i = 0; i < a.size(); i++) {
        if (!a[i][0]) continue;
        if (j == K - 2) { kmoo = i; }
        if (j == K - 1) {
            ko = i;
            a[kmoo][1] += a[i][1];
        }
        j++;
    }

    a.erase(a.begin() + ko);

    for (auto [type, db] : a) {
        cout << string(db, "01"[type]);
    }
    cout << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
