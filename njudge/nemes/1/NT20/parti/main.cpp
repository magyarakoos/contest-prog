#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)
#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define has(s, e) s.count(e)

using namespace std;
using ll = long long;
using point = array<int, 2>;

int N;
vector<vector<int>> g;
vector<int> indegS;

void remove(int node, int deg) {
    indegS[node] = -1;
    for (int neighbor : g[node]) {
        indegS[neighbor]--;
        if (!indegS[neighbor]) {
            remove(neighbor, deg);
        }
    }
}

int main() {
    speed;

    cin >> N;
    g.resize(N + 1);
    indegS.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        int U, V;
        cin >> U >> V;
        g[i].push_back(U);
        g[i].push_back(V);
        indegS[U]++;
        indegS[V]++;
    }

    for (int i = 0; i < 2; i++) {
        for (int node = 1; node <= N; node++) {
            if (indegS[node] == i) {
                remove(node, i);
            }
        }
    }

    vector<int> result;

    for (int i = 1; i <= N; i++) {
        if (indegS[i] == 2) {
            result.push_back(i);
        }
    }

    cout << result.size() << '\n';
    for (int n : result) cout << n << ' ';
}
