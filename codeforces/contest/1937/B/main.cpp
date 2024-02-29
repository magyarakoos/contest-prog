#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

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

        queue<array<int, 3>> q;

        int curr_round = 1;

        q.push({0, 0, 0});

        vector<bool> path(N + 1, 1);
        int count = 1;
        path[0] = v[0][0];

        while (!q.empty()) {
            auto [x, y, round] = q.front(); q.pop();

            if (curr_round < round) {
                // előző kör kiértékelése, megszámoljuk hány jó van
                
                curr_round = round;
            }

            if (x == N - 1 && y == N - 1) {
                continue;
            }

            if (y == 1) {
                if (v[x][y]) {
                    if path[round]
                }
            } else {

            }
        }
    };
}