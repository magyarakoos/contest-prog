#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x, y, i;
    bool operator<(Point p) { return x == p.x ? y < p.y : x < p.x; }
};

struct Triangle {
    Point a, b, c;
};

int turn();

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

    Triangle tri = {ptS[0], ptS[1], ptS[2]};
    for (int i = 2; i < N; i++) {
        if (ptS[i].x > ptS[0].x) {
            tri.c = ptS[i];
            break;
        }
    }

    for (int i = 3; i < N - 1; i++) {
        if (in_triangle(tri, ptS[i])) {
            sort(tri.begin(), tri.end());
            tri[0] = ptS[i];
        }
    }

    for (int i = 0; i < 3; i++) {
        cout << find(ptS.begin(), ptS.end(), tri[i]) - ptS.begin() + 1 << " ";
    }
}
