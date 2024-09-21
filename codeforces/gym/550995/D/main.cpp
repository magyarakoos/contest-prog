#include <algorithm>
#include <iostream>
#include <vector>

using ll = long long;
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

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;

    vector<Point> ptS(N);
    for (int i = 0; i < N; i++) {
        cin >> ptS[i].x >> ptS[i].y;
        ptS[i].i = i;
    }

    sort(ptS.begin() + 2, ptS.end());

    cout << ptS[0].i + 1 << " " << ptS[1].i + 1 << " "
         << (*find_if(ptS.begin() + 2, ptS.end(), [&](Point p) {
                return turn(ptS[0], ptS[1], p);
            })).i;
}
