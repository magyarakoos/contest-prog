#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int BASEA = 29, BASEB = 31, MODA = 1e9 + 9,
          MODB = 1e9 + 7;

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
    for (int i = 0; i < 15; i++) cout << primes[i] << " ";
    cout << "\n";

    cin.tie(0)->sync_with_stdio(0);
    int n;
    string s;
    cin >> n >> s;

    vector<array<int, 2>> ps(n + 1), pw(n + 1);
    for (int i = 1; i <= n; i++) {
        pw[i] = {pw[i - 1][0] * BASEA % MODA,
                 pw[i - 1][1] * BASEB % MODB};
        ps[i] = {ps[i - 1][0] * BASEA % MODA,
                 ps[i - 1][1] * BASEB % MODB};
        (ps[i][0] += s[i - 1] - 'a' + 1) %= MODA;
        (ps[i][1] += s[i - 1] - 'a' + 1) %= MODB;
    }
    auto get = [&](int l, int r) -> array<int, 2> {
        return {(ps[r][0] + MODA -
                 ps[l][0] * pw[r - l][0] % MODA) %
                    MODA,
                (ps[r][1] + MODB -
                 ps[l][1] * pw[r - l][1] % MODB) %
                    MODB};
    };

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        auto [x, y] = get(l, r + 1);
        cout << s.substr(l, r - l + 1) << " " << x << " "
             << y << "\n";
    }
}
