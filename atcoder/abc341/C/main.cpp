#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;

int H, W, N;
string T;
vector<vector<bool>> grid;

bool solve(int i, int j, int p = 0) {

    if (p == size(T))
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    cin >> H >> W >> N >> T;

    grid.assign(H, vector<bool>(W));

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char c;
            cin >> c;
            grid[i][j] = c == '.';
        }
    }

    int result = 0;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grid[i][j]) {
                result += solve(i, j);
            }
        }
    }
}