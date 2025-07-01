#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    vector<bool> is_prime(1e6 + 1, 1);
    is_prime[1] = 0;
    for (int i = 2; i <= 1e6; i++) {
        if (!is_prime[i]) continue;
        for (int j = i * 2; j <= 1e6; j += i) {
            is_prime[j] = 0;
        }
    }
    int n, x;
    cin >> n;
    while (n--) {
        cin >> x;
        int y = sqrt(x) + 0.5;
        cout << (y * y == x && is_prime[y] ? "YES" : "NO")
             << "\n";
    }
}
