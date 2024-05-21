#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    
    int N, M, Q;
    cin >> N >> M >> Q;

    vector distS(N + 1, vector<ll>(N + 1, INF));
    
    for (int i = 1; i <= N; i++) {
        distS[i][i] = 0;
    }

    while (M--) {
        ll U, V, W;
        cin >> U >> V >> W;
        distS[U][V] = min(W, distS[U][V]);
        distS[V][U] = min(W, distS[V][U]);
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                distS[i][j] = min(distS[i][j], distS[i][k] + distS[k][j]);
            }
        }
    }

    while (Q--) {
        int U, V;
        cin >> U >> V;
        cout << (distS[U][V] == INF ? -1 : distS[U][V]) << "\n";
    }
}
