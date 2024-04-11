
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using point = array<int, 2>;

int N, M, T, P, E, INF = 1e9;
vector<vector<point>> g;

void bfs(int s, vector<vector<int>>& d) {
    d[s] = 0;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    cin >> N >> M >> T >> P >> E;

    g.resize(N + 1);
    vector<vector<int>> tom(N + 1), jerry(N + 1);
    while (M--) {
        int A, B, S;
        cin >> A >> B >> S;
    
        g[A].push_back({B, S});
        g[B].push_back({A, S});
    }


    while (P--) {
        int K;
        cin >> K;
        cout << (K & 1 ? "IGEN" : "NEM") << '\n';
    }
}