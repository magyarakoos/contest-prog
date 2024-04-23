#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 3e5;
int N;

int bfs(const vector<vector<int>>& g, int s) {

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

	return node;
}

vector<int> bfs2(const vector<vector<int>>& g, int s) {

	vector<bool> vis(N + 1);
	vector<int> distS(N + 1, INF);
	queue<int> q;

	vis[s] = 1;
	distS[s] = 0;
	q.push(s);

	while (!q.empty()) {
		int u = q.front(); q.pop();

		for (int v : g[u]) {
			if (!vis[v]) {
				vis[v] = 1;
				distS[v] = distS[u] + 1;
				q.push(v);
			}
		}
	}

	return distS;
}

int main() {
	cin >> N;
	if (N == 1) {
		cout << 0;
		exit(0);
	}

	vector<vector<int>> g(N + 1);
	for (int i = 1; i < N; i++) {
		int A, B;
		cin >> A >> B;
		g[A].push_back(B);
		g[B].push_back(A);
	}

	int node1 = bfs(g, 1);
	int node2 = bfs(g, node1);

	auto distS1 = bfs2(g, node1);
	auto distS2 = bfs2(g, node2);

	for (int i = 1; i <= N; i++) {
		cout << max(distS1[i], distS2[i]) << " ";
	}
	cout << "\n";
}
