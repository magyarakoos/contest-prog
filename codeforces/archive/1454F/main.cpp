#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;
int lg[MAXN + 1];

void preproc(vector<vector<int>>& st, function<int(int, int)> f) {}

void solve() {
    int N;
    cin >> N;

    vector<int> lg(N + 1), a(N);
    vector<vector<int>> stmn(25, vector<int>(N)),
        stmx(25, vector<int>(N));

    for (int& x : a) cin >> x;

    copy(a.begin(), a.end(), stmn[0].begin());
    copy(a.begin(), a.end(), stmx[0].begin());

    preproc(stmn, [](int a, int b) { return a < b ? a : b; });
    preproc(stmx, [](int a, int b) { return a > b ? a : b; });
}

int main() {
    for (int i = 2; i <= MAXN; i++) { lg[i] = lg[i / 2] + 1; }
    int T;
    cin >> T;
    while (T--) solve();
}
