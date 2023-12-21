#include <iostream>
#include <vector>
#include <set>

using namespace std;
#define speed cin.tie(0); ios::sync_with_stdio(0)

vector<vector<int>> neighborS;
set<int> result;

void dfs(int node, int parent) {
    for (int neighbor : neighborS[node]) {
        if (neighbor == parent) continue;
        result.insert(neighbor);
        if (neighborS[neighbor].size() > 2) continue;
        dfs(neighbor, node);
    }
}

int main() {
    speed;

    int N, M;
    cin >> N >> M;

    neighborS.resize(N + 1);
    
    while (M--) {
        int U, V;
        cin >> U >> V;
        neighborS[U].push_back(V);
        neighborS[V].push_back(U);
    }

    for (int i = 1; i <= N; i++) {
        if (neighborS[i].size() == 1) { // zsakfalu
            dfs(i, 0);
        }
    }

    cout << result.size() << '\n';
    for (int node : result) cout << node << ' ';
}
