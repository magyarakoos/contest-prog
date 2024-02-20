#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

constexpr array<int, 2> dirs[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int N;
string s;
vector<string> m;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    cin >> N;
    
    m.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> m[i];
    }

    cin >> s;

    queue<array<int, 2>> q;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (m[i][j] == s[0]) {
                q.push({i, j});
            }
        }
    }

    vector<vector<bool>> vis(N, vector<bool>(N));

    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();

        vis.assign(N, vector<bool>(N, 0));

        int si = i, sj = j;

        int p = 1;

        string path;

        while (p < N) {
            bool step = 0;
            for (auto [dy, dx] : dirs) {
                int y = i + dy, x = j + dx;

                if (y < 0 || x < 0 || y >= N || x >= N || vis[y][x]) {
                    continue;
                }
                
                if (m[y][x] == s[p]) {
                    p++;
                    step = 1;
                    i = y;
                    j = x;

                    path += (
                        dy == 1 && dx == 0 ? 'L' :
                        dy == -1 && dx == 0 ? 'F' :
                        dy == 0 && dx == 1 ? 'J' :
                        'B'
                    );
                    break;
                }
            }
            if (!step) {
                goto next;
            }
        }

        cout << si + 1 << ' ' << sj + 1 << '\n' << path;

        next:continue;
    }
}