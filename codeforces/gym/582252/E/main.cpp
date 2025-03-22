#include <bits/stdc++.h>
using namespace std;
#define int int64_t
using point = array<int, 2>;
using node = array<point, 2>;

// Cross product to determine orientation
int turn(const point& A, const point& B, const point& C) {
    return (B[0] - A[0]) * (C[1] - A[1]) -
           (B[1] - A[1]) * (C[0] - A[0]);
}

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);

    // Read polygon A
    int N;
    cin >> N;
    vector<node> P;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        P.push_back({{x, y}, {0, i}});
    }

    // Read polygon B
    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        P.push_back({{x, y}, {1, i}});
    }

    // Check for duplicate points
    sort(P.begin(), P.end());
    for (int i = 1; i < P.size(); i++) {
        if (P[i - 1][0][0] == P[i][0][0] &&
            P[i - 1][0][1] == P[i][0][1]) {
            // Duplicate point found - one polygon vertex
            // lies on another
            cout << "NO\n";
            return 0;
        }
    }

    // Sort points by polar angle with respect to P[0]
    sort(P.begin() + 1, P.end(), [&](node A, node B) {
        int t = turn(P[0][0], A[0], B[0]);
        if (t != 0) return t > 0;
        // If collinear, sort by distance
        int d1 = (A[0][0] - P[0][0]) * (A[0][0] - P[0][0]) +
                 (A[0][1] - P[0][1]) * (A[0][1] - P[0][1]);
        int d2 = (B[0][0] - P[0][0]) * (B[0][0] - P[0][0]) +
                 (B[0][1] - P[0][1]) * (B[0][1] - P[0][1]);
        return d1 < d2;
    });

    // Graham scan to find convex hull
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

    // Check if any point of B is part of the convex hull
    for (const auto& node : hull) {
        if (node[1][0] ==
            1) { // It's a point from polygon B
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
}
