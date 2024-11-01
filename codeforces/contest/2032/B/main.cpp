#include <bits/stdc++.h>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;

#define cases 1
void solve() {
    i32 N, K;
    cin >> N >> K;
    i32 la = K - 1, lb = N - K;
    if (la == 0 && lb == 0) {
        cout << "1\n1\n";
    } else if (la > 0 && lb > 0) {
        cout << "3\n";
        if (la & 1 && lb & 1) {
            cout << "1 " << K << " " << K + 1 << "\n";
        } else if (!(la & 1) && !(lb & 1)) {
            cout << "1 " << K - 1 << " " << K + 2 << "\n";
        } else {
            cout << "-1\n";
        }
    } else {
        cout << "-1\n";
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
