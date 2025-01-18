#include <bits/stdc++.h>
using namespace std;
using point = array<int64_t, 2>;

int turn(point a, point b, point c) {
    int64_t p = (a[0] - b[0]) * (a[1] - c[1]) -
                (a[1] - b[1]) * (a[0] - c[0]);
    return (p > 0) - (p < 0);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    vector<pair<point, int>> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i].first[0] >> a[i].first[1];
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    sort(a.begin() + 1, a.end(), [&](auto b, auto c) {
        int t = turn(a[0].first, b.first, c.first);
        return (t != 0 ? t == 1 : b < c);
    });
    int i = N - 1;
    while (turn(a[i].first, a[i - 1].first,
                a[i - 2].first) == 0)
        i--;
    for (auto [xy, i] : a) cout << i + 1 << " ";
    cout << "\n";
}
