#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

vector<vector<int>> g;
vector<int> indegS, dp;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;
    
    g.resize(N + 1);
    indegS.resize(N + 1);
    dp.assign(N + 1, INF);
    while (M--) {
        int U, V;
        cin >> U >> V;
        g[U].push_back(V);
        indegS[V]++;
    }

    // magic starting node
    for (int u = 1; u <= N; u++) {
        g[0].push_back(u);
    }


}