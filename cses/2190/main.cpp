#include <iostream>

using namespace std;
using ll = long long;
using Point = struct {
    ll x, y;
};

inline int sign(ll x) { return (0 < x) - (0 > x); }

int turn(Point A, Point B, Point C) {
    return sign((B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x));
}

bool on_segment(Point A, Point B, Point C) {
    return !turn(A, B, C) && min(A.x, B.x) <= C.x && C.x <= max(A.x, B.x) &&
           min(A.y, B.y) <= C.y && C.y <= max(A.y, B.y);
}

bool lsi(Point A, Point B, Point C, Point D) {
    return on_segment(A, B, C) || on_segment(A, B, D) || on_segment(C, D, A) ||
           on_segment(C, D, B) ||
           (turn(A, B, C) != turn(A, B, D) && turn(C, D, A) != turn(C, D, B));
}

void solve() {
    Point A, B, C, D;
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
    cout << (lsi(A, B, C, D) ? "YES" : "NO") << "\n";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}
