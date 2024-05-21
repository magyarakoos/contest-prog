#include <bits/stdc++.h>
#include <magyarakoos-debug.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;

int main() {
	cin.tie(0), ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;
    
    vector<array<int, 3>> edgeS(M);
    for (auto& [U, V, W] : edgeS) cin >> U >> V >> W;

    vector distS(N + 1, INF);
    vector<int> nxt(N + 1, 1);

    distS[1] = 0;

    for (int i = 0; i < N - 1; i++) {
        for (auto [u, v, w] : edgeS) {
            if (distS[u] + w < distS[v]) {
                nxt[u] = v;
                distS[v] = distS[u] + w;
            }
        }
    }

    for (auto [u, v, w] : edgeS) {
        if (distS[u] + w < distS[v]) {
            cout << "YES\n" << u;
            int curr = u;
            do {
                curr = nxt[curr];
                cout << " " << curr;
            } while (curr != u);
            exit(0);
        }
    }

    cout << "NO\n";
}
