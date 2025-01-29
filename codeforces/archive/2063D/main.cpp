#include <bits/stdc++.h>
using namespace std;
#define int int64_t

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M);
    for (int& x : A) cin >> x;
    for (int& x : B) cin >> x;

    vector<int> result(1);
    int al = 0, ar = N - 1, bl = 0, br = M - 1;
    while (1) {
        int la = ar - al + 1, lb = br - bl + 1;
        bool can_a = la >= 2 && lb >= 1,
             can_b = lb >= 2 && la >= 1;
        if (can_a && can_b) {
            if (la > lb) {
                result.push_back(result.back() + la);
                al++, ar--;
            } else {
                result.push_back(result.back() + lb);
                bl++, br--;
            }
        }
    }
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}
