#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using Point = struct {
    ll x, y;
};

const string s[] = {"OUTSIDE", "INSIDE", "BOUNDARY"};
const ll INF = 2e9;

int sign(ll x) { return (x > 0) - (x < 0); }

int turn(Point A, Point B, Point C) {
    return sign((B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x));
}

bool on_line(Point A, Point B, Point C) {
    return !turn(A, B, C) && min(A.x, B.x) <= C.x && C.x <= max(A.x, B.x) &&
           min(A.y, B.y) <= C.y && C.y <= max(A.y, B.y);
}

bool intersect(Point A, Point B, Point C, Point D) {
    return on_line(A, B, C) || on_line(A, B, D) || on_line(C, D, A) ||
           on_line(C, D, B) ||
           (turn(A, B, C) != turn(A, B, D) && turn(C, D, A) != turn(C, D, B));
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    vector<Point> ptS(N);
    for (auto& [x, y] : ptS) cin >> x >> y;
    ptS.push_back(ptS[0]);

    while (M--) {
        Point p;
        cin >> p.x >> p.y;
        int result = 0, icnt = 0;

        for (int i = 1; i <= N; i++) {
            if (on_line(ptS[i - 1], ptS[i], p)) {
                result = 2;
                break;
            }
            icnt += intersect(p, {p.x + 1, INF}, ptS[i - 1], ptS[i]);
        }

        if (!result) result = icnt & 1;

        cout << s[result] << "\n";
    }
}
