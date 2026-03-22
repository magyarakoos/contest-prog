#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 5e4, BASEA = 29, BASEB = 31,
          MODA = 1e9 + 9, MODB = 1e9 + 7;

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    string s;
    cin >> n >> s;

    vector<bool> spf(MAXN, 1);
    spf[0] = 0;
    for (int i = 2; i < MAXN; i++) {
        if (!spf[i]) continue;
        for (int j = i * 2; j < MAXN; j += i) {
            if (spf[j] == 1) spf[j] = i;
        }
    }
    auto factorize = [&](int a) {
        vector<int> result;
        if (spf[a]) {
            result.push_back(a);
            return result;
        }
    };

    vector<array<int, 2>> ps(n + 1), pw(n + 1);
    pw[0] = {1, 1};
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
                 ps[l - 1][0] * pw[r - l + 1][0] % MODA) %
                    MODA,
                (ps[r][1] + MODB -
                 ps[l - 1][1] * pw[r - l + 1][1] % MODB) %
                    MODB};
    };
    auto is_per = [&](int l, int r, int p) {
        auto [hla, hlb] = get(l, r - p);
        auto [hra, hrb] = get(l + p, r);
        return hla == hra && hlb == hrb;
    };

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l++, r++;
        bool ok = 0;
        for (int i = 0; primes[i] * 2 <= r - l + 1; i++) {
            if (is_per(l, r, primes[i])) {
                ok = 1;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}
