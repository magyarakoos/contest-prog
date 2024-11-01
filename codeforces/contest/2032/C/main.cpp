#include <bits/stdc++.h>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;

#define cases 1
void solve() {
    i32 N;
    cin >> N;
    vector<i32> a(N);
    for (i32& x : a) cin >> x;

    sort(a.begin(), a.end());

    i32 result = N - 1;
    for (i32 i = 0; i < N - 1; i++) {
        i32 l = i, r = N;
        while (r - l > 1) {
            i32 m = (l + r) / 2;
            if (a[i] + a[min(i + 1, m)] <= a[m]) {
                r = m;
            } else {
                l = m;
            }
        }
        result = min(result, i + (N - l - 1));
    }
    cout << result << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
