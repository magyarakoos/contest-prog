#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;

    vector<ll> d(n + 1, LLONG_MIN);
    d[1] = 0;

    vector<array<ll, 3>> edgeS(m);
    for (auto& [u, v, w] : edgeS) { cin >> u >> v >> w; }

    for (int i = 1; i <= n; i++) {
        for (auto [u, v, w] : edgeS) {
            if (d[u] != LLONG_MIN) {
                d[v] = max(d[v], d[u] + w);
            }
        }
    }

    ll tav = d[n];

    for (auto [u, v, w] : edgeS) {
        if (d[u] != LLONG_MIN) {
            d[v] = max(d[v], d[u] + w);
        }
    }

    if (d[n] > tav) {
        cout << "inf\n";
    } else {
        cout << tav << "\n";
    }
}
