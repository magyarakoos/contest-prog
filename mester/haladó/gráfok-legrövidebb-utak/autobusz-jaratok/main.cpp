#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    vector<array<int, 3>> edgeS(M);

    for (int i = 0; i < M; i++) {
        int U, V, W;
        cin >> U >> V >> W;
        edgeS[i] = {U, V, W};
    }

    vector<ll> distS(N + 1, INF);
    vector<int> prv(N + 1);

    int S, E;
    cin >> S >> E;

    distS[S] = 0;

    for (int i = 1; i <= N - 1; i++) {
        for (auto [u, v, w] : edgeS) {
            if (distS[u] + w < distS[v]) {
                distS[v] = distS[u] + w;
                prv[v] = u;
            }
        }
    }

    cout << abs(distS[E]) << "\n";

    stack<int> s;
    while (E) {
        s.push(E);
        E = prv[E];
    }

    cout << s.size() << "\n";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n";
}
