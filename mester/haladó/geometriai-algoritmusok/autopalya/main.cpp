#include <bits/stdc++.h>
using namespace std;
#define int int64_t

using point = array<int, 2>;
using node = array<point, 2>;

int turn(point A, point B, point C) {
    return (B[0] - A[0]) * (C[1] - A[1]) -
           (B[1] - A[1]) * (C[0] - A[0]);
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);

    vector<node> P(2e5);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> P[i][0][0] >> P[i][0][1];
        P[i][1] = {0, i};
    }
    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> P[i + N][0][0] >> P[i + N][0][1];
        P[i + N][1] = {1, i - N};
    }
    P.resize(N + M);

    sort(P.begin(), P.end());
    sort(P.begin() + 1, P.end(), [&](node A, node B) {
        int t = turn(P[0][0], A[0], B[0]);
        return t ? t > 0 : A[0] < B[0];
    });

    for (node A : P) {
        cout << A[0][0] << " " << A[0][1] << "\n";
    }
}
