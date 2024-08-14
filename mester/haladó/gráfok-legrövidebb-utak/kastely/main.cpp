
#include <bits/stdc++.h>

#pragma region Utility

#define speed cin.tie(0); ios::sync_with_stdio(0)
#define cinv(v) for (auto& e : v) cin >> e;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()
#define has(s, e) s.count(e)

#define max_index(v) max_element(all(v)) - v.begin()
#define min_index(v) min_element(all(v)) - v.begin()
#define smax(x, y) x = max(x, y)
#define smin(x, y) x = min(x, y)

#define sum(v) accumulate(all(v), 0)
#define product(v, T) accumulate(all(v), 1, multiplies<T>())

using namespace std;
using ll = long long;
using point = array<int, 2>;

int max(point p) { return max(p[0], p[1]); }
int min(point p) { return min(p[0], p[1]); }

template <typename T>
vector<T> prefix_sum(const vector<T>& v) {
    vector<T> result(size(v));
    partial_sum(all(v), result.begin());
    return result;
}

#pragma endregion

struct Route {
    int x;
    int y;
    int dist;
    bool operator()(Route a, Route b) {
        return a.dist > b.dist;
    }
};

constexpr point cardir[] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
constexpr point diagdir[] = {{-1, -1}, {1, 1}, {-1, 1}, {1, -1}};

int main() {
    speed;

    int N, M, R;
    cin >> N >> M >> R;

    point s, e;
    cin >> s[1] >> s[0] >> e[1] >> e[0];
    s[0]--; s[1]--; e[0]--; e[1]--;

    vector<vector<int>> costS(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> costS[i][j];
        }
    }

    vector<vector<int>> distS(N, vector<int>(M, 1e9));
    priority_queue<Route, vector<Route>, Route> pq;

    pq.push({s[0], s[1], 0});
    distS[s[1]][s[0]] = 0;

    while (!pq.empty()) {

        auto [x, y, dist] = pq.top(); pq.pop();

        if (distS[y][x] != dist) {
            continue;
        }

        for (auto [nx, ny] : cardir) {
            
            int dx = x + nx, dy = y + ny;

            if (dx < 0 || dy < 0 || dx >= M || dy >= N) {
                continue;
            }

            int ndist = dist + costS[dy][dx];

            if (ndist < distS[dy][dx]) {
                distS[dy][dx] = ndist;
                pq.push({dx, dy, ndist});
            }
        }

        for (auto [nx, ny] : diagdir) {

            int dx = x + nx, dy = y + ny;

            if (dx < 0 || dy < 0 || dx >= M || dy >= N) {
                continue;
            }

            int ndist = dist + costS[dy][dx] + R;

            if (ndist < distS[dy][dx]) {
                distS[dy][dx] = ndist;
                pq.push({dx, dy, ndist});
            }
        }
    }

    cout << distS[e[1]][e[0]] << '\n';
}
