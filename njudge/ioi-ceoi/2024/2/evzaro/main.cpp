#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using point = array<int, 2>;

map<point, pair<int, bool>> m;
vector<point> v;

void bfs(point s) {
    m[s].second = 1;
    queue<pair<point, int>> q({{s, 0}});
    while (!q.empty()) {
        auto [pos, dist] = q.front(); q.pop();
        
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i][0] >> v[i][1];
        m[{v[i][0], v[i][1]}] = {i, 0};
    }
    string s(N, 'L');
    for (int i = 0; i < N; i++) {
        if (!m[v[i]].second) {
            bfs(v[i]);
        }
    }
}