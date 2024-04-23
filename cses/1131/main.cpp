#include <bits/stdc++.h>
using namespace std;
int N;

array<int, 2> bfs(const vector<vector<int>>& g, int s) {

	vector<bool> vis(N + 1);
	queue<array<int, 2>> q;

	vis[s] = 1;
	q.push({s, 0});

	int max_dist = 0, node = 0;

	while (!q.empty()) {
		auto [u, dist] = q.front(); q.pop();

		if (max_dist < dist) {
			max_dist = dist;
			node = u;
		}

		for (int v : g[u]) {
			if (!vis[v]) {
				vis[v] = 1;
				q.push({v, dist + 1});
			}
		}
	}

	return {node, max_dist};
}

int main() {
	cin >> N;
	vector<vector<int>> g(N + 1);
	for (int i = 1; i < N; i++) {
		int A, B;
		cin >> A >> B;
		g[A].push_back(B);
		g[B].push_back(A);
	}

	auto [node, _] = bfs(g, 1);
	cout << (bfs(g, node))[1];
}
