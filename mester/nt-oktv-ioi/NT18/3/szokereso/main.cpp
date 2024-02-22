#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define size(v) (int)v.size()

using namespace std;
using ll = long long;
using point = array<int, 2>;

constexpr point dirs[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int N;
vector<vector<char>> grid;
string s;

void solve()

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


            }
        }
    }
}