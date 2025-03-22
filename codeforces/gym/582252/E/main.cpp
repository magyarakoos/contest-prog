#include <bits/stdc++.h>
using namespace std;
using point = array<int64_t, 2>;

int fordul(point A, point B, point C) {
    return (B[0] - A[0]) * (C[1] - A[1]) -
           (C[0] - A[0]) * (B[1] - A[1]);
}

bool kozte(point A, point B, point C) {
    return (fordul(A, B, C) == 0 &&
            (max(A[0], B[0]) >= C[0] &&
             min(A[0], B[0]) <= C[0]) &&
            (max(A[1], B[1]) >= C[1] &&
             min(A[1], B[1]) <= C[1]));
}

vector<point> hull(vector<point> ptS) {
    int N = ptS.size();

    sort(ptS.begin(), ptS.end());
    sort(ptS.begin() + 1, ptS.end(), [&](point a, point b) {
        if (fordul(ptS[0], a, b) == 0 &&
            !kozte(ptS[0], a, b)) {
            return true;
        }
        return fordul(ptS[0], a, b) > 0;
    });

    vector<point> result({ptS[0]});
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
        if (!fordul(ptS[0], ptS.back(), ptS[i])) {
            result.push_back(ptS[i]);
        } else
            break;
    }
    return result;
}

vector<point> read(vector<point> a) {
    int N;
    cin >> N;
    while (N--) {
        int x, y;
        cin >> x >> y;
        a.push_back({x, y});
    }
    return a;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    auto A = read({});
    auto AB = hull(read(A));
    sort(A.begin(), A.end());
    sort(AB.begin(), AB.end());

    cout << (A == AB ? "YES" : "NO") << "\n";
}
