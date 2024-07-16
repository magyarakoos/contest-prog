#include <iostream>

using namespace std;
using ll = long long;
using Point = struct {
    ll x, y;
};

string fordul(Point A, Point B, Point C) {
    ll p = (A.x - B.x) * (A.y - C.y) - (A.y - B.y) * (A.x - C.x);
    return p > 0 ? "LEFT" : p < 0 ? "RIGHT" : "TOUCH";
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        Point A, B, C;
        cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
        cout << fordul(A, B, C) << "\n";
    }
}
