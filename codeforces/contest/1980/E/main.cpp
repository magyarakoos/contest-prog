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

    vector<int> pos1i(N * M), pos2i(N * M), pos1j(N * M),
        pos2j(N * M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int x = A[i][j];
            int y = B[i][j];
            pos1i[x] = pos2i[y] = i;
            pos1j[x] = pos2j[y] = j;
        }
    }
    vector<set<int>> pi(nm), pj(nm);
    for (int x = 0; x < nm; ++x) {
        int i1 = pos1i[x], i2 = pos2i[x];
        int j1 = pos1j[x], j2 = pos2j[x];
        pi[i1].insert(i2);
        pj[j1].insert(j2);
    }
    for (int x = 0; x < nm; ++x) {
        if (pi[x].size() > 1 || pj[x].size() > 1) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) { solve(); }
    return 0;
}
