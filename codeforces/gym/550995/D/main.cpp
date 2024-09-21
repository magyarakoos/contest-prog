#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Point {
    ll x, y;
    int i;
    bool operator<(Point p) { return x == p.x ? y < p.y : x < p.x; }
};

bool turn(Point& a, Point& b, Point& c) {
    return (a.x - c.x) * (b.y - c.y) - (a.y - c.y) * (b.x - c.x);
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

    cout << ptS[0].i + 1 << " " << ptS[1].i + 1 << " ";
    for (int i = 2; i < N; i++) {
        if (turn(ptS[0], ptS[1], ptS[i])) {
            cout << i << " " << ptS[i].x << " " << ptS[i].y << "\n";
            cout << ptS[i].i;
            break;
        }
    }
}
