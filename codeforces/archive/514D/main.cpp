#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;

int lg[MAXN + 1], st[25][MAXN];

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int>> droids(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) { cin >> droids[i][j]; }
    }

    for (int i = 2; i <= MAXN; i++) { lg[i] = lg[i / 2] + 1; }

    for (int i) }
