
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using point = array<int, 2>;

int N, M, T, P, E, INF = 1e9;
vector<vector<point>> g;

int main() {
    speed;

    cin >> N >> M >> T >> P >> E;

    g.resize(N + 1);
    tom.resize(N + 1);
    jerry.resize(N + 1);
    while (M--) {
        int A, B, S;
        cin >> A >> B >> S;
    
        g[A].push_back({B, S});
        g[B].push_back({A, S});
    }
    vector<vector<int>> tom(N + 1,), jerry;



    while (P--) {
        int K;
        cin >> K;
        cout << (K & 1 ? "IGEN" : "NEM") << '\n';
    }
}