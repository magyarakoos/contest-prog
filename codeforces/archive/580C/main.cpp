#include <bits/stdc++.h>
using namespace std;

#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<bool> catS(N + 1);
    for (int i = 1; i <= N; i++) {
        char b;
        cin >> b;
        catS[i] = b == '1';
    }

    vector<vector<int>> g(N + 1);

    for (int i = 1; i < N; i++) {
        int U, V;
        cin >> U >> V;
        g[U].push_back(V);
        g[V].push_back(U);
    }

    vector<bool> vis(N + 1);
    queue<array<int, 2>> q({{1, catS[1]}});
    
    while (!q.empty()) {
        
    }
}