#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define smin(x, y) x = min(x, y)
#define smax(x, y) x = max(x, y)

#define cases 0
void solve() {
    int N;
    cin >> N;
    vector<vector<char>> v(N, vector<char>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> v[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c;
            cin >> c;
            if (c != v[i][j]) {
                cout << i + 1 << " " << j + 1 << "\n";
                return;
            }
        }
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
