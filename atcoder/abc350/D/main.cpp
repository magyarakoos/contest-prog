#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> g;
vector<bool> vis;
vector<int> sizeS;

#define cases 0
void solve() {
    int N, M;
    cin >> N >> M;
    vis.resize(N + 1);
    g.resize(N + 1);
    for (int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;
        g[U].push_back(V);
        g[V].push_back(U);
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}