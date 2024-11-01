#include <bits/stdc++.h>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;

#define cases 1
void solve() {
    i32 N, zc = 0;
    cin >> N;
    for (i32 i = 0; i < 2 * N; i++) {
        i32 x;
        cin >> x;
        zc += !x;
    }
    i32 oc = 2 * N - zc;
    cout << N - (zc / 2 + oc / 2) << " ";
    cout << min(zc, oc) << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
