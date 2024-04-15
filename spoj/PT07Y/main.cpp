#include <bits/stdc++.h>
using namespace std;
#define end(b) cout << (b ? "YES" : "NO"); exit(0)
vector<vector<int>> g;

int main() {
    int N, M;
    cin >> N >> M;
    if (M != N - 1) end(0);
    g.resize(N + 1);
    while (M--) {
        int U, V;
        cin >> U >> V;
        g[U].push_back(V);
        g[V].push_back(U);
    }
    
}