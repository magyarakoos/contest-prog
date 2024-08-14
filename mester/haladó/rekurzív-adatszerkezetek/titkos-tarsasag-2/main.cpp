#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()
#define has(s, e) s.count(e)

using namespace std;
using ll = long long;

vector<vector<int>> g;

int free_spots(int s) {
    int result = 0;

    for (int employee : g[s]) {
        result += employee ? free_spots(employee) : 1;
    }

    return result;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, K;
    cin >> N >> K;

    g.assign(N + 1, vector<int>(K));

    for (int i = 2; i <= N; i++) {
        int u, w;
        cin >> u >> w;
        g[u][w - 1] = i;
    }

    int p1 = 0;
    vector<int> p2(K);

    for (int i = 0; i < K; i++) {
        if (g[1][i]) {
            p2[i] = free_spots(g[1][i]);
        } else {
            p1++;
        }
    }

    cout << p1 << '\n';
    for (int x : p2) cout << x << ' ';
    cout << '\n';
}
