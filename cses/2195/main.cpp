#include <bits/stdc++.h>
using namespace std;
using point = array<int, 2>;

int turn(point a, point b) {
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
    sort(a.begin(), a.end(),
         [](array<int, 2> a, array<int, 2> b) {
             return a < b;
         });
}
