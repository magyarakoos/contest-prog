#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0), ios::sync_with_stdio(0);
  int N, M, T, P, E;
  cin >> N >> M >> T >> P >> E;
  vector<vector<int>> jg(N + 1), tg(N + 1);
  while (M--) {
    int U, V, W;
    cin >> U >> V >> W;
    jg[U].push_back(V);
    jg[V].push_back(U);
    if (W == 2) {
      tg[U].push_back(V);
      tg[V].push_back(U);
    }
  }

  vector<int> tom(N + 1, INT_MAX);
  queue<int> q({T});
  tom[T] = 0;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (auto v : tg[u]) {
      if (tom[v] == INT_MAX) {
        tom[v] = tom[u] + 1;
        q.push(v);
      }
    }
  }

  vector<bool> jerry(N + 1);
  jerry[E] = 1;
  priority_queue<array<int, 2>> pq;
  pq.push({tom[E], E});
  while (!pq.empty()) {
    auto [u_t, u] = pq.top();
    pq.pop();
    if (u_t < 0)
      continue;
    jerry[u] = true;
    for (int v : jg[u]) {
      if (jerry[v])
        continue;
      // jerry should be at position `v`
      // not later than `T = dist_from_tom[v] - 1` to avoid getting caught
      // not later than `T = u_t - 1` so that they can step to `u` right after
      pq.push({min(tom[v] - 1, u_t - 1), v});
    }
  }

  while (P--) {
    int jerry_start;
    cin >> jerry_start;
    cout << (jerry[jerry_start] ? "IGEN" : "NEM") << endl;
  }
}
