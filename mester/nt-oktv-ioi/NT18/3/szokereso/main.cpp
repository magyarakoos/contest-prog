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

        int p = 1;

        while (p < N) {

        }
    }
}