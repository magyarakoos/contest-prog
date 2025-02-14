#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int digsum(int n) {
    return n ? n % 10 + digsum(n / 10) : 0;
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < 5e3; i++) {
            if (digsum(N) == i) {
                cout << i << "\n";
                break;
            }
        }
    }
}
