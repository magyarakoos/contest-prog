#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

constexpr array<int, 2> dirs[] = {{1, 0}, {0, 1}};

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<array<bool, 2>> v(N);
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < N; j++) {
                char c;
                cin >> c;
                v[j][i] = c == '1';
            }
        }
        
        queue<array<int, 4>> q;
        q.push({0, 0, 0, 0});

        int curr_d = 0;

        string path = to_string(v[0][0]);

        bool has_z = 0;
        
        int count = 0;

        while (!q.empty()) {
            auto [x, y, dist, prv] = q.front();
            q.pop();

            if (curr_d < dist) {
                if (has_z) {
                    path += '0';
                } else {
                    path += '1';
                }
                has_z = 0;
                curr_d = dist;
            }

            if (path.back() == '0' && prv) {
                continue;
            }

            if (dist == N) {
                count++;
                continue;
            }

            for (auto [dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;
                if (nx < N && ny < 2) {
                    q.push({nx, ny, dist + 1, v[nx][ny]});
                    if (!v[nx][ny]) has_z = 1;
                }
            }
        }

        cout << path << '\n' << count << '\n';
    };
}