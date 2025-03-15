#include <bits/stdc++.h>
using namespace std;
#define int __int128

int isqrt(int n) {
    int l = 0, r = n + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (m * m == n) {
            return m;
        } else if (m * m < n) {
            l = m;
        } else {
            r = m;
        }
    }
    return -1;
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int64_t _N;
    cin >> _N;
    int N = _N;

    for (int i = 1; i <= 1e6; i++) {
        if (N % i) continue;

        int b = 3 * i,
            D = isqrt(b * b - 12 * (i * i - N / i));

        if (D != -1 && (D - b) % 6 == 0 && D > b) {
            int64_t y = (D - b) / 6, x = y + i;
            cout << x << " " << y << "\n";
            return 0;
        }
    }

    cout << "-1\n";
}
