#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;
using point = array<int, 2>;

constexpr point dirs[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
constexpr char d[] = "LFJB";

int N;
vector<vector<char>> grid;
string s;

void solve(int si, int sj, int i, int j, int p, string path,
    vector<vector<bool>> vis    
) {
    if (p == N) {
        cout << si + 1 << ' ' << sj + 1 << '\n' << path;
        exit(0);
    }

    bool step = 0;

    for (int k = 0; k < 4; k++) {

        int di = i + dirs[k][0];
        int dj = j + dirs[k][1];

        if (di < 0 || dj < 0 || di >= N || dj >= N || vis[di][dj]) {
            continue;
        }


    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    cin >> N;

    grid.assign(N, vector<char>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> s;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {

            if (grid[i][j] == s[0]) {

                vector<vector<bool>> vis(N, vector<bool>(N));
                vis[i][j] = 1;

                solve(i, j, i, j, 0, "", vis);
            }
        }
    }

    cout << "0 0";
}