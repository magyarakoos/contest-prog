#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

struct Point {
    ll x, y, i;
    bool operator<(Point p) { return x == p.x ? y < p.y : x < p.x; }
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
    return abs(turn(tri[0], tri[1], p) + turn(tri[1], tri[2], p) +
               turn(tri[0], tri[2], p)) == 3 ||
           on_line(tri[0], tri[1], p) || on_line(tri[0], tri[1], p) ||
           on_line(tri[0], tri[1], p);
}

int main() {
    int N;
    cin >> N;

    vector<Point> ptS(N);
    for (int i = 0; i < N; i++) {
        cin >> ptS[i].x >> ptS[i].y;
        ptS[i].i = i;
    }

    sort(ptS.begin() + 2, ptS.end());

    vector<Point> tri = {ptS[0], ptS[1]};

    int i = 2;
    for (; i < N; i++) {
        if (!on_line(tri[0], tri[1], ptS[i])) {
            tri.push_back(ptS[i]);
            break;
        }
    }

    for (i++; i < N; i++) {
        bool oa = on_line(tri[0], tri[1], ptS[i]),
             ob = on_line(tri[1], tri[2], ptS[i]),
             oc = on_line(tri[0], tri[2], ptS[i]);
        if (in_triangle(tri, ptS[i]) || oa || ob || oc) {
            tri[!oa ? 2 : !ob ? 0 : 1] = ptS[i];
        }
    }

    cout << tri[0].i + 1 << " " << tri[1].i + 1 << " " << tri[2].i + 1 << "\n";
}
