#include <bits/stdc++.h>
using namespace std;
#define int int64_t

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M);
    for (int& x : A) cin >> x;
    for (int& x : B) cin >> x;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    vector<int> result(1);
    int al = 0, ar = N - 1, bl = 0, br = M - 1, ca = 0,
        cb = 0;
    while (1) {
        int la = ar - al + 1 + ca, lb = br - bl + 1 + cb;
        bool can_a = la >= 2 && lb >= 1,
             can_b = lb >= 2 && la >= 1;
        if (can_a && can_b) {
            if (la > lb) {
                result.push_back(result.back() +
                                 (A[ar] - A[al] + 1));
                al++, ar--;
                cb++;
            } else {
                result.push_back(result.back() +
                                 (B[br] - B[bl] + 1));
                bl++, br--;
                ca++;
            }
        } else if (can_a && !can_b) {
            result.push_back(result.back() + la);
            al++, ar--;
        } else if (!can_a && can_b) {
            result.push_back(result.back() + lb);
            bl++, br--;
        } else if (!can_a && !can_b) {
            if (la == 0 && lb >= 3) {
                al--, ar++;
            } else if (la >= 3 && lb == 0) {
                bl--, br++;
            } else {
                break;
            }
        } else {
            assert(0);
        }
    }
    cout << result.size() - 1 << "\n";
    for (int i = 1; i < result.size(); i++)
        cout << result[i] << " ";
    cout << "\n";
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}
