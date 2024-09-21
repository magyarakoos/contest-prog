#include <algorithm>
#include <iostream>
#include <vector>
using ll = long long;

using namespace std;
using Point = struct {
    ll x, y, i;
}

struct Point {
    ll x, y;
    int i;
};

int turn(Point& a, Point& b, Point& c) {
    ll r = (a.x - c.x) * (b.y - c.y) - (a.y - c.y) * (b.x - c.x);
    return (r > 0) - (r < 0);
}

bool on_line(Point a, Point b, Point c) {
    return !turn(a, b, c) && min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x) &&
           min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y);
}

bool in_triangle(vector<Point> tri, Point p) {
    int a = turn(tri[0], tri[1], p) + turn(tri[1], tri[2], p) +
            turn(tri[0], tri[2], p);
    return abs(a) == 3;
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;

    vector<Point> ptS(N);
    for (int i = 0; i < N; i++) {
        cin >> ptS[i].x >> ptS[i].y;
        ptS[i].i = i;
    }

    sort(ptS.begin(), ptS.end());

    vector<Point> tri = {ptS[0], ptS[1], ptS[2]};
    for (int i = 2; i < N; i++) {
        if (ptS[i].x > ptS[0].x) {
            tri[2] = ptS[i];
            break;
        }
    }

    for (int i = 3; i < N - 1; i++) {
        bool oa = on_line(tri[0], tri[1], ptS[i]),
             ob = on_line(tri[1], tri[2], ptS[i]),
             oc = on_line(tri[0], tri[2], ptS[i]);
        if (in_triangle(tri, ptS[i])) {}
    }

    cout << tri[0].i + 1 << " " << tri[1].i + 1 << " " << tri[2].i + 1 << "\n";
}
