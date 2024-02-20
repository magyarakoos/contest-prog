#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

constexpr int INF = 1e9;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;

    vector<vector<int>> g(N + 1);

    for (int i = 2; i <= N; i++) {
        int U;
        cin >> U;
        g[U].push_back(i);
    }

    vector<int> distS(N + 1);
    queue<array<int, 2>> q;

    q.push({1, 0});

    int mx = 0;

    while (!q.empty()) {
        auto [node, dist] = q.front();
        q.pop();

        if (g[node].empty()) {
            distS[node] = dist;
            mx = max(mx, dist);
            continue;
        }

        for (int child : g[node]) {
            q.push({child, dist + 1});
        }
    }

    vector<int> result;

    for (int i = 1; i <= N; i++) {
        if (distS[i] == mx) {
            result.push_back(i);
        }
    }

    cout << size(result) << ' ' << mx << '\n';
    for (int x : result) cout << x << ' ';
    cout << '\n';
}