#include <bits/stdc++.h>
using namespace std;
using point = array<int64_t, 2>;

int fordul(point A, point B, point C) {
    int64_t P = (B[0] - A[0]) * (C[1] - A[1]) -
                (C[0] - A[0]) * (B[1] - A[1]);
    return P ? P < 0 ? -1 : 1 : 0;
}

bool kozte(point A, point B, point C) {
    return (fordul(A, B, C) == 0 &&
            (max(A[0], B[0]) >= C[0] &&
             min(A[0], B[0]) <= C[0]) &&
            (max(A[1], B[1]) >= C[1] &&
             min(A[1], B[1]) <= C[1]));
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    Point base;
    int N;
    cin >> N;

    vector<Point> ptS(N);
    base = {INT_MAX, INT_MAX};

    for (int i = 0; i < N; i++) {
        cin >> ptS[i].x >> ptS[i].y;

        if (ptS[i].x < base.x) {
            base = ptS[i];
        } else if (base.x == ptS[i].x &&
                   ptS[i].y < base.y) {
            base.y = ptS[i].y;
        }
    }

    sort(ptS.begin(), ptS.end());
    sort(ptS.begin() + 1, ptS.end(), [&](pointa, pointb) {
        if (fordul(base, a, b) == 0 && !kozte(base, a, b)) {
            return true;
        }
        return fordul(base, a, b) == 1;
    });

    vector<Point> result({base});
    int K = 0;

    for (int i = 1; i < N; i++) {
        while (K > 0 && fordul(result[K - 1], result[K],
                               ptS[i]) < 0) {
            K--;
            result.pop_back();
        }
        K++;
        result.push_back(ptS[i]);
    }

    for (int i = N - 2; i >= 1; i--) {
        if (!fordul(base, ptS.back(), ptS[i])) {
            result.push_back(ptS[i]);
        } else
            break;
    }

    cout << result.size() << "\n";
    for (pointp : result) cout << p.x << " " << p.y << "\n";
}
