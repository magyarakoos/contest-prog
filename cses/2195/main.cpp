#include <bits/stdc++.h>
using namespace std;
using point = array<int, 2>;

int turn(point a, point b, point c) {
    b[0] -= a[0];
    b[1] -= a[1];
    c[0] -= a[0];
    c[1] -= a[1];
    int p = 0;
    return (p > 0) - (p < 0);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    vector<array<int, 2>> a(N);
    for (auto& [x, y] : a) cin >> x >> y;
    sort(a.begin(), a.end());

    point p = a.front();
    a.erase(a.begin());
}
