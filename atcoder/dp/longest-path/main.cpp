#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;
    
    g.resize(N + 1);
    while (M--) {
        int U, V;
        cin >> U >> V;
        g[U].push_back(V);
        g[V].push_back(U);
    }

    // magic starting node
    for (int u = 1; u <= N; u++) {
        g[0].push_back(u);
    }
}