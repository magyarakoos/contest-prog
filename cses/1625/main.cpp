#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) (int)v.size()

using namespace std;
using ll = long long;

int result;
string s, t;
bool grid[4][4];

const int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};

void backtrack(int i, int j, int steps) {
    if (i == 3 && j == 0 && steps == 48) {
        result++;
        return;
    }
    for (int k = 0; k < 4; k++) {
        int ni = i + di[k], nj = j + dj[k];
        if (ni < 0 || nj < 0 || ni >= 4 || nj >= 4 || grid[ni][nj]) {
            continue;
        }
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    //cin >> s;
    //t.assign(sz(s), '?');
    backtrack(0, 0, 0);
}