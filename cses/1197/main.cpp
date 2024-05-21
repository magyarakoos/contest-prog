#include <bits/stdc++.h>
#ifdef LOCAL
#include <magyarakoos-debug.h>
#else
#define DB(...)
#endif
using namespace std;
using ll = long long;

const ll INF = 1e18;

vector<int> path(int u, const vector<int>& prv) {
    vector<int> res;
    map<int, int> m;

    int curr = prv[u];
    do {
        res.push_back(curr);
        if (m.contains(curr)) {
            return vector<int>(res.begin() + m[curr], res.end());
        }
        m[curr] = res.size() - 1;
        curr = prv[curr];
    } while(1);

    return {};
}

int main() {
	cin.tie(0), ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;
    
    vector<array<int, 3>> edgeS(M);
    for (auto& [U, V, W] : edgeS) cin >> U >> V >> W;

    vector distS(N + 1, INF);
    vector<int> prv(N + 1);

    distS[1] = 0;

    for (int i = 0; i < 2 * N; i++) {
        for (auto [u, v, w] : edgeS) {
            if (distS[u] + w < distS[v]) {
                prv[v] = u;
                distS[v] = distS[u] + w;
            }
        }
    }

    for (auto [u, v, w] : edgeS) {
        if (distS[u] + w < distS[v]) {
            prv[v] = u;
            cout << "YES\n";
            auto p = path(v, prv);
            reverse(p.begin(), p.end());
            for (int x : p) cout << x << " ";
            cout << "\n";
            exit(0);
        }
    }

    cout << "NO\n";
}
