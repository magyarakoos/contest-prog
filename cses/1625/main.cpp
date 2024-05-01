#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) (int)v.size()

using namespace std;
using ll = long long;

const int SZ = 5;

int result;
string s, t;
bool grid[SZ][SZ];

const int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};

int l(int i) {
    if (i == 0) return 3;
    return i - 1;
}

int r(int i) {
    if (i == 3) return 0;
    return i + 1;
}

void backtrack(int i, int j, int steps, int prv_i, int prv_j) {
    if (i == SZ - 1 && j == 0) {
        if (steps == SZ * SZ - 1) {
            result++;
        }
        return;
    }
    vector<tuple<char, int, int>> moveS(4, {'?', 0, 0});
    vector<bool> can(4);

    int nk;
    for (int k = 0; k < 4; k++) {
        int ni = i + di[k], nj = j + dj[k];

        if (ni == prv_i && nj == prv_j) {
            nk = k;
        }
        
        char step = "DURL"[k];
        if (t[steps] != '?' && t[steps] != step) {
            continue;
        }

        if (ni < 0 || nj < 0 || ni >= SZ || nj >= SZ || grid[ni][nj]) {
            continue;
        }

        moveS[i] = {step, ni, nj};
        can[i] = 1;
    }
    if (steps > 0) {
        for (int k = 0; k < 4; k++) {
            if (k == nk) continue;
            if (!can[k] && can[l(k)] && can[r(k)]) {
                return;
            }
        }
    }
    for (auto [step, ni, nj] : moveS) {
        if (step != '?') {
            grid[ni][nj] = 1;
            s[steps] = step;
            backtrack(ni, nj, steps + 1, i, j);
            grid[ni][nj] = 0;
        }
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    
    cin >> t;
    s.assign(sz(t), '?');

    grid[0][0] = 1;
    backtrack(0, 0, 0, 0, 0);
    cout << result;
}