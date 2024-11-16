#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> read(int N, int M) {
    vector a(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
            a[i][j]--;
        }
    }
    return a;
}

void solve() {
    int N, M;
    cin >> N >> M;
    auto A = read(N, M), B = read(N, M);

    vector<int> posi(N * M), posci(N * M), posj(N * M),
        poscj(N * M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            posi[A[i][j]] = posci[B[i][j]] = i;
            posj[A[i][j]] = poscj[B[i][j]] = j;
        }
    }

    vector<set<int>> pi(N * M), pj(N * M);

    for (int x = 0; x < N * M; x++) {
        int i1 = posi[x], i2 = posci[x];
        int j1 = posj[x], j2 = poscj[x];
        pi[i1].insert(i2);
        pj[j1].insert(j2);
    }

    for (int x = 0; x < N * M; ++x) {
        if (pi[x].size() > 1 || pj[x].size() > 1) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}
