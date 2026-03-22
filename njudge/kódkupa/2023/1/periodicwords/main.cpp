#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    vector<bool> is_prime(1e5 + 1, 1);
    vector<int> primes;
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i <= 1e5; i++) {
        if (!is_prime[i]) continue;
        primes.push_back(i);
        for (int j = i * 2; j <= 1e5; j += i) {
            is_prime[j] = 0;
        }
    }

    cin.tie(0)->sync_with_stdio(0);

    for (int i = 0; i < 15; i++) cout << primes[i] << " ";

    int n, s;
    cin >> n >> s;

    cout << "\n";
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
    }
}
