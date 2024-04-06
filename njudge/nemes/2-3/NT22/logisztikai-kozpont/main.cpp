#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()
#define has(s, e) s.count(e)

using namespace std;
using ll = long long;

int N;
vector<vector<pair<int, ll>>> g;
vector<ll> distS;
vector<int> parS;

void dfs(int u, int par) {
    for (auto [v, w] : g[u]) {
        if (v == par) continue;
        if (distS[v] < distS[u] + w) {
            distS[v] = distS[u] + w;
            parS[v] = u;
        }
        dfs(v, u);
    }
}

void proc(int start, int end) {
    cout << start << " " << end << "\n";
    for (int i = 1; i <= N; i++) cout << distS[i] << " ";
    cout << "\n";


}

void get_ends(int start) {
    distS.assign(N + 1, 0);
    parS .assign(N + 1, 0);

    dfs(start, 0);
    int end = max_element(all(distS)) - distS.begin();

    for (int u = 1; u <= N; u++) {
        if (distS[u] == distS[end]) {
            proc(start, u);
        }
    }
}

int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    cin >> N;

    g.resize(N + 1);
    distS.resize(N + 1);
    parS.resize(N + 1);
    for (int i = 1; i < N; i++) {
        int U, V, W;
        cin >> U >> V >> W;
        g[U].push_back({V, W});
        g[V].push_back({U, W});
    }

    dfs(1, 0);
    int start = max_element(all(distS)) - distS.begin();

    for (int u = 1; u <= N; u++) {
        if (distS[u] == distS[start]) {
            get_ends(u);
        }
    }
}
