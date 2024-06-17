#include <bits/stdc++.h>
using namespace std;
using ll = long long;

array<int, 2> to_slope(int x, int y) {
    return {x / gcd(x, y), y / gcd(x, y)};
}

int main() {
	cin.tie(0), ios::sync_with_stdio(0);

    int N, x0, y0;
    cin >> N >> x0 >> y0;

    int dx = -x0, dy = -y0;

    set<array<int, 2>> slopeS;

    bool at_origin = 0;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        x += dx;
        y += dy;

        if (x == 0 && y == 0) {
            at_origin = 1;
        }
        else if ((x > 0 && y > 0) || (x < 0 && y > 0) || (x == 0 && y > 0) || (x > 0 && y == 0)) {
            slopeS.insert(to_slope(x, y));
        }
        else {
            slopeS.insert(to_slope(-x, -y));
        }
    }

    if (slopeS.empty()) {
        cout << at_origin << "\n";
    }
    else {
        cout << slopeS.size() << "\n";
    }
}
