#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int N;
int t = 1;

vector<int> g;
vector<bool> vis;
vector<int> path;

void dfs(int u) {

}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    cin >> N;

    g.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        int u;
        cin >> u;
        g[i] = u;
    }

    vis.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            dfs(i);
        }
    }
}