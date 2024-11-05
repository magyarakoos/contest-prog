#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = LLONG_MAX;

int main() {
    int N, M;
    cin >> N >> M;

    vector<ll> d(N + 1, -INF);
    d[1] = 0;

    vector<array<ll, 3>> edgeS(M);
    for (auto& [u, v, w] : edgeS) { cin >> u >> v >> w; }

    for (int i = 1; i <= N; i++) {
        for (auto [u, v, w] : edgeS) {
            if (d[u] != -INF) {
                d[v] = max(d[v], d[u] + w);
            }
        }
    }

    ll dN = d[N];

    for (auto [u, v, w] : edgeS) {
        if (d[u] != -INF) { d[v] = max(d[v], d[u] + w); }
    }

    if (d[N] > dN) {
        cout << "inf\n";
    } else {
        cout << dN << "\n";
    }
}
