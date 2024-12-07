#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define cases 0
void solve() {
    int H, W, D;
    cin >> H >> W >> D;
    vector<vector<bool>> a(H, vector<bool>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char c;
            cin >> c;
            a[i][j] = c == '.';
        }
    }
    int result = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            for (int k = 0; k < H; k++) {
                for (int l = 0; l < W; l++) {
                    int curr = 0;
                    for (int m = 0; m < H; m++) {
                        for (int n = 0; n < W; n++) {
                            curr +=
                                (abs(i - m) + abs(j - n) <=
                                     D ||
                                 abs(k - m) + abs(l - n) <=
                                     D) &&
                                a[m][n] && a[i][j] &&
                                a[k][l];
                        }
                    }
                    result = max(result, curr);
                }
            }
        }
    }
    cout << result << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T = 1;
    if (cases) cin >> T;
    while (T--) solve();
}
