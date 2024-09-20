#include <algorithm>
#include <iostream>
#include <vector>
using llong = long long;
using ll = llong;

using namespace std;

struct Point {
    ll x, y;
    int i;
    bool operator<(Point p) { return x == p.x ? y < p.y : x < p.x; }
};

int turn(Point& a, Point& b, Point& c) {
    ll r = (a.x - c.x) * (b.y - c.y) - (a.y - c.y) * (b.x - c.x);
    return (r > 0) - (r < 0);
}

bool on_line(Point a, Point b, Point c) {
    return !turn(a, b, c) && min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x);
}

bool in_triangle(vector<Point> tri, Point p) {
    int a = turn(tri[0], tri[1], p) + turn(tri[1], tri[2], p) +
            turn(tri[0], tri[2], p);
    return abs(a) == 3 || on_line(tri[0], tri[1], p) ||
           on_line(tri[1], tri[2], p) || on_line(tri[0], tri[2], p);
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
        if (in_triangle(tri, ptS[i])) {
            sort(tri.begin(), tri.end());
            tri[2] = ptS[i];
        }
    }

    for (int i = 0; i < 3; i++) {
        cout << find(ptS.begin(), ptS.end(), tri[i]) - ptS.begin() + 1 << " ";
    }
}
