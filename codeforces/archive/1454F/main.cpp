#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int lg[MAXN + 1];

void preproc(int N, vector<vector<int>>& st,
             function<int(int, int)> f) {
    for (int i = 1; i < 25; i++) {
        for (int j = 0; j + (1 << i) <= N; j++) {
            st[i][j] = f(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
    }
}

void solve() {
    int N;
    cin >> N;

    vector<int> lg(N + 1), a(N);
    vector<vector<int>> st(25, vector<int>(N));

    map<int, int> fp;

    for (int& x : a) cin >> x;

    auto rmn = [&](int l, int r) -> int {
        int i = lg[r - l + 1];
        return min(stmn[i][l], stmn[i][r - (1 << i) + 1]);
    };

    for (int i = 2; i < N; i++) {
        int right_mx = rmx(i, N - 1);

        int l = fp[right_mx] - 1, r = i - 1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (rmn(m, i - 1) >= right_mx) {
                r = m;
            } else {
                l = m;
            }
        }
        if (r - 1 <= 0) continue;

        cout << rmx(0, r - 1) << " " << rmn(r - 1, i - 1) << " "
             << rmx(i, N - 1) << "\n";
        cout << r << " " << i - r << " " << N - i << "\n";
        cout << "\n";
    }
}

int main() {
    for (int i = 2; i <= MAXN; i++) { lg[i] = lg[i / 2] + 1; }
    int T;
    cin >> T;
    while (T--) solve();
}
