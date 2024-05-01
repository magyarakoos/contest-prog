#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) (int)v.size()

using namespace std;
using ll = long long;

int result;
string s, t;
bool grid[4][4];

void backtrack(int i, int j, int steps) {
    if (i == 3 && j == 0 && steps == 48) {
        result++;
        return;
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> s;
    t.assign(sz(s), '?');
    backtrack(0, 0, 0);
}