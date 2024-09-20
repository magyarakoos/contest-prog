#include <algorithm>
#include <iostream>
#include <vector>
using llong = long long;
using ll = llong;

using namespace std;

struct Point {
    long long x, y;
    int i;
    bool operator<(Point p) { return x == p.x ? y < p.y : x < p.x; }
};

int turn(Point& a, Point& b, Point& c) {
    long long r = (a.x - c.x) * (b.y - c.y) - (a.y - c.y) * (b.x - c.x);
    return (r > 0) - (r < 0);
}

bool in_triangle(vector<Point> tri, Point p) { return 0; }

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
