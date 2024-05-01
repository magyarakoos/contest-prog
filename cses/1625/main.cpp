#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) (int)v.size()

using namespace std;
using ll = long long;

const int SZ = 4;

int result;
string s;
bool grid[SZ][SZ];

const int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};

void backtrack(int i, int j, int steps) {
    if (i == SZ - 1 && j == 0 && steps == SZ * SZ - 1) {
        result++;
        cout << s << "\n";
        return;
    }
    for (int k = 0; k < 4; k++) {
        int ni = i + di[k], nj = j + dj[k];
        if (ni < 0 || nj < 0 || ni >= SZ || nj >= SZ || grid[ni][nj]) {
            continue;
        }
        grid[ni][nj] = 1;
        s += "DURL"[k];
        backtrack(ni, nj, steps + 1);
        grid[ni][nj] = 0;
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    backtrack(0, 0, 0);
    cout << result;
}