#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) (int)v.size()

using namespace std;
using ll = long long;

const int SZ = 7;

int result;
string s, t;
bool grid[SZ][SZ];

const int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};

void backtrack(int i, int j, int steps) {
    if (i == SZ - 1 && j == 0) {
        if (steps == SZ * SZ - 1) {
            result++;
        }
        return;
    }
    vector<tuple<char, int, int>> moveS(4);
    for (int k = 0; k < 4; k++) {
        char step = "DURL"[k];
        if (t[steps] != '?' && t[steps] != step) {
            continue;
        }

        int ni = i + di[k], nj = j + dj[k];
        if (ni < 0 || nj < 0 || ni >= SZ || nj >= SZ || grid[ni][nj]) {
            continue;
        }

        moveS[i] = {step, ni, nj};
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    
    cin >> t;
    s.assign(sz(t), '?');

    grid[0][0] = 1;
    backtrack(0, 0, 0);
    cout << result;
}