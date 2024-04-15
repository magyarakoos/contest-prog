#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<int>> g;

int main() {
    int N, M;
    cin >> N >> M;
    g.resize(N + 1);
    while (M--) {
        int U, V;
        cin >> U >> V;
        g[U].push_back(V);
    }
}
