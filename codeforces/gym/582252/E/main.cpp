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
        P[i + N][1] = {1, i};
    }
    P.resize(N + M);

    sort(P.begin(), P.end());

    for (int i = 1; i < N + M; i++) {
        if (P[i - 1][0] == P[i][0]) {
            cout << "NO\n";
            return 0;
        }
    }

    sort(P.begin() + 1, P.end(), [&](node A, node B) {
        int t = turn(P[0][0], A[0], B[0]);
        return t ? t > 0 : A[0] < B[0];
    });

    vector<node> hull({P[0], P[1]});
    int K = 2;
    for (int i = 2; i < N + M; i++) {
        while (K >= 2 &&
               turn(hull[K - 2][0], hull[K - 1][0],
                    P[i][0]) < 0) {
            hull.pop_back();
            K--;
        }
        hull.push_back(P[i]);
        K++;
    }

    sort(hull.begin(), hull.end());
    hull.resize(unique(hull.begin(), hull.end()) -
                hull.begin());

    for (int i = 0; i < K; i++) {
        if (hull[i][1][0]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}

