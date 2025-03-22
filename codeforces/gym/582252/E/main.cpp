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
    for (int i = 1; i < P.size(); i++) {
        if (P[i - 1][0][0] == P[i][0][0] &&
            P[i - 1][0][1] == P[i][0][1]) {
            cout << "NO\n";
            return 0;
        }
    }

    sort(P.begin() + 1, P.end(), [&](node A, node B) {
        int t = turn(P[0][0], A[0], B[0]);
        if (t != 0) return t > 0;
        int d1 =
            (A[0][0] - P[0][0][0]) *
                (A[0][0] - P[0][0][0]) +
            (A[0][1] - P[0][0][1]) * (A[0][1] - P[0][0][1]);
        int d2 =
            (B[0][0] - P[0][0][0]) *
                (B[0][0] - P[0][0][0]) +
            (B[0][1] - P[0][0][1]) * (B[0][1] - P[0][0][1]);
        return d1 < d2;
    });

    vector<node> hull;
    hull.push_back(P[0]);
    hull.push_back(P[1]);

    for (int i = 2; i < P.size(); i++) {
        while (hull.size() >= 2 &&
               turn(hull[hull.size() - 2][0],
                    hull[hull.size() - 1][0],
                    P[i][0]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(P[i]);
    }

    for (const auto& node : hull) {
        if (node[1][0] == 1) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}
