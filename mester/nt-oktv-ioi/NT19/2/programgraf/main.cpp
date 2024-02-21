#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)
#define all(v) v.begin(), v.end()

using namespace std;

// it's important to note here that this does not work.
int main() {
    speed;

    int N, M;
    cin >> N >> M;

    vector<bool> vis(N + 1);
    vector<vector<int>> g(N + 1);

    while (M--) {
        int U, V;
        cin >> U >> V;
        g[U].push_back(V);
    }

    queue<int> q;
    q.push(1);
    vis[1] = 1;

    vector<bool> loop(N + 1), branch(N + 1);

    while (!q.empty()) {
        int n = q.front(); q.pop();

        if (g[n].size() == 2) {
            branch[n] = 1;
        }

        for (int next : g[n]) {
            if (vis[next]) {
                loop[n] = 1;
                continue;
            }
            vis[next] = 1;
            q.push(next);
        }
    }
    int loop_sum = accumulate(all(loop), 0), branch_sum = accumulate(all(branch), 0);
    cout << loop_sum << '\n' << branch_sum;
}
