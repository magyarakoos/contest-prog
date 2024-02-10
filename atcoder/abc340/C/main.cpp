#include <bits/stdc++.h>

#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()
#define has(s, e) s.count(e)

using namespace std;
using ull = unsigned long long;

unordered_map<ull, ull> cache;

ull solve(ull n) {
    if (has(cache, n)) {
        return cache[n];
    }

    if (n < 2) {
        return 0;
    }

    ull a = n / 2,
        b = n / 2 + (n & 1);

    ull sa = solve(a),
        sb = solve(b);

    cache[n] = sa + sb;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    ull N;
    cin >> N;

    cout << solve(N);
}