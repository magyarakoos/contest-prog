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

  vector<int> dist_from_tom(N + 1, INT_MAX);
  queue<int> tq;
  tq.push(T);
  dist_from_tom[T] = 0;
  while (!tq.empty()) {
    int u = tq.front();
    tq.pop();
    for (auto v : tg[u]) {
      if (dist_from_tom[v] != INT_MAX)
        continue;
      dist_from_tom[v] = dist_from_tom[u] + 1;
      tq.push(v);
    }
  }
  vector<bool> can_jerry_start_at(N + 1);
  can_jerry_start_at[E] = true;
  priority_queue<array<int, 2>> pq;
  pq.push({dist_from_tom[E], E});
  while (!pq.empty()) {
    auto [u_t, u] = pq.top();
    pq.pop();
    if (u_t < 0)
      continue;
    can_jerry_start_at[u] = true;
    for (int v : jg[u]) {
      if (can_jerry_start_at[v])
        continue;
      // jerry should be at position `v`
      // not later than `T = dist_from_tom[v] - 1` to avoid getting caught
      // not later than `T = u_t - 1` so that they can step to `u` right after
      pq.push({min(dist_from_tom[v] - 1, u_t - 1), v});
    }
  }

  while (P--) {
    int jerry_start;
    cin >> jerry_start;
    cout << (can_jerry_start_at[jerry_start] ? "IGEN" : "NEM") << endl;
  }
}
