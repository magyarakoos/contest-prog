#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using Point = struct {
    ll x, y;
};

int main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N;
    cin >> N;

    vector<Point> ptS(N);
    for (auto& [x, y] : ptS) cin >> x >> y;
    ptS.push_back(ptS[0]);

    ll result = 0;

    for (int i = 1; i <= N; i++) {
        result += ptS[i - 1].x * ptS[i].y - ptS[i - 1].y * ptS[i].x;
    }

    cout << abs(result) << "\n";
}
