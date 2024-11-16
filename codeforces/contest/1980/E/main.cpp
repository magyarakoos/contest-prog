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

    vector<int> pai(N * M), pbi(N * M), paj(N * M),
        pbj(N * M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            pai[A[i][j]] = pbi[B[i][j]] = i;
            paj[A[i][j]] = pbj[B[i][j]] = j;
        }
    }

    vector<set<int>> pi(N * M), pj(N * M);

    for (int x = 0; x < N * M; x++) {
        pi[pai[x]].insert(pbi[x]);
        pj[paj[x]].insert(pbj[x]);
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
