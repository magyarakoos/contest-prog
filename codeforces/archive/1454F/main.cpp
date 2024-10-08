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
    vector<vector<int>> stmn(25, vector<int>(N)),
        stmx(25, vector<int>(N));

    map<int, int> fp;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
        if (!fp.count(a[i])) fp[a[i]] = i;
    }

    copy(a.begin(), a.end(), stmn[0].begin());
    copy(a.begin(), a.end(), stmx[0].begin());

    preproc(N, stmn, [](int a, int b) { return a < b ? a : b; });
    preproc(N, stmx, [](int a, int b) { return a > b ? a : b; });

    // TODO: implement these
    auto rmn = [&](int l, int r) -> int { return 0; };
    auto rmx = [&](int l, int r) -> int { return 0; };

    for (int i = 2; i < N; i++) {
        int right_mx = rmx(i, N - 1);

        int l = fp[right_mx] - 1, r = i - 1;

        if (l >= r) continue;
    }
}

int main() {
    for (int i = 2; i <= MAXN; i++) { lg[i] = lg[i / 2] + 1; }
    int T;
    cin >> T;
    while (T--) solve();
}
