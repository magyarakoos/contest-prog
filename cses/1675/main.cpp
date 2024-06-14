#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> lnk, crd;

int find(int u) {
    while (u != lnk[u]) u = lnk[u];
    return lnk[u];
}

bool same(int u, int v) {
    return find(u) == find(v);
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (crd[v] < crd[u]) swap(u, v);
    crd[u] += crd[v];
    lnk[v] = u;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    vector<array<int, 3>> edgeS(M);

    lnk.resize(N + 1);
    iota(lnk.begin(), lnk.end(), 0);
    crd.assign(N + 1, 1);

    for (int i = 0; i < M; i++) {
        cin >> edgeS[i][1] >> edgeS[i][2] >> edgeS[i][0];
    }

    sort(edgeS.begin(), edgeS.end());

    ll result = 0;

    for (auto [w, u, v] : edgeS) {
        if (!same(u, v)) {
            unite(u, v);
            result += w;
        }
    }

    cout << result << "\n";
}
