#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()
#define has(s, e) s.count(e)

using namespace std;
using ll = long long;

int N;
vector<vector<pair<int, ll>>> g;
vector<ll> distS, par_distS;
vector<int> parS;

ll result_t = 1e18;
vector<int> result_nodeS;

void dfs(int u, int par) {
    for (auto [v, w] : g[u]) {
        if (v == par) continue;
        if (distS[v] < distS[u] + w) {
            distS[v] = distS[u] + w;
            parS[v] = u;
            par_distS[v] = w;
        }
        dfs(v, u);
    }
}

void proc(int start, int end) {
    cout << start << " " << end << "\n";
    for (int i = 1; i <= N; i++) cout << distS[i] << " ";
    cout << "\n";

    vector<pair<int, ll>> path;
    int curr = end;

    do {
        path.push_back({curr, par_distS[curr]});
        curr = parS[curr];
    } while (curr);

    ll sum = 0;
    for (auto [u, w] : path) sum += w;

    ll running_sum = 0;
    for (int i = 0; i < N; i++) {
        ll curr = max(running_sum, sum - running_sum);
        if (curr < result_t) {
            result_t = curr;
            result_nodeS.clear();
            result_nodeS.push_back()
        }
    }
}

void get_ends(int start) {
    distS    .assign(N + 1, 0);
    parS     .assign(N + 1, 0);
    par_distS.assign(N + 1, 0);

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

    if (N == 1) {
        cout << "0\n1\n1";
        exit(0);
    }

    g        .resize(N + 1);
    distS    .resize(N + 1);
    parS     .resize(N + 1);
    par_distS.resize(N + 1);

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
