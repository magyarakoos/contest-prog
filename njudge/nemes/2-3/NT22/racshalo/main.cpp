#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

#define speed cin.tie(0); ios::sync_with_stdio(0)

struct Route {
public:
    int node;
    int length;
    bool operator()(Route a, Route b) {
        return a.length > b.length;
    }
};

vector<vector<int>> neighborS;
vector<int> distanceS;
int N, M, K, m_size;


int dijkstra(int s) {
    for (int i = 1; i <= m_size; i++) {
        distanceS[i] = INT_MAX;
    }

    priority_queue<Route, vector<Route>, Route> pq;

    pq.push({s, 0});
    distanceS[s] = 0;

    while (!pq.empty()) {
        Route next = pq.top();
        pq.pop();

        if (next.length != distanceS[next.node]) continue;

        for (int neighbor : neighborS[next.node]) {

            int dist = distanceS[next.node] + 1;

            if (dist < distanceS[neighbor]) {

                distanceS[neighbor] = dist;
                pq.push({neighbor, dist});
            }
        }
    }

    return *max_element(distanceS.begin() + 1, distanceS.end());
}

int main() {
    speed;

    cin >> N >> M >> K;
    m_size = N * M;

    neighborS.resize(m_size + 1);

    for (int i = 0, p = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            p++;
            if (i) neighborS[p].push_back(p - M);
            if (i < N - 1) neighborS[p].push_back(p + M);
            if (j) neighborS[p].push_back(p - 1);
            if (j < M - 1) neighborS[p].push_back(p + 1);
        }
    }

    distanceS.resize(m_size + 1);

    while (K--) {
        int U, V;
        cin >> U >> V;

        neighborS[U].push_back(V);
        neighborS[V].push_back(U);

        int curr_max = 0;
        for (int i = 1; i <= m_size; i++) {
            curr_max = max(curr_max, dijkstra(i));
        }

        cout << curr_max << '\n';
    }
}
