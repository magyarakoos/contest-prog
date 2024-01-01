#include <bits/stdc++.h>

#define speed cin.tie(0); ios::sync_with_stdio(0)
#define cinv(v) for (auto& e : v) cin >> e;
#define all(v) v.begin(), v.end()
#define has(s, e) s.count(e)

using namespace std;
using ll = long long;
using point = array<int, 2>;

int main() {
    speed;

    int N;
    cin >> N;

    vector<point> g(N + 1);
    vector<int> indegS(N + 1);

    for (int i = 1; i <= N; i++) {
        int U, V;
        cin >> U >> V;
        g[i][0] = U;
        g[i][1] = V;
        indegS[U]++;
        indegS[V]++;
    }

    queue<int> q;

    for (int i = 1; i <= N; i++) {
        if (indegS[i] < 2) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int i = 0; i < 2; i++) {
            int next = g[node][i];

            if (--indegS[next] == 1) {
                q.push(next);
            }
        }
    }

    vector<int> result;

    for (int i = 1; i <= N; i++) {
        if (indegS[i] >= 2) {
            result.push_back(i);
        }
    }

    cout << result.size() << '\n';
    for (int n : result) cout << n << ' ';
    cout << '\n';
}
