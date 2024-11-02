#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
#define int long long

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);

    int N, K;
    cin >> N >> K;
    vector<int> p(N);
    for (int& x : p) cin >> x;

    int goal = N * K;
    int avg = accumulate(p.begin(), p.end(), 0LL);

    auto f = [&](int c) -> bool {
        if (avg == goal) { return 1; }
        if (avg < goal) { return avg + N * c >= goal; }
        int d = 0;
        for (int x : p) { d += min(x - 1, c); }
        return avg - d <= goal;
    };

    int l = -1, r = 2e9;
    while (r - l > 1) {
        int m = (r + l) / 2;
        if (f(m)) {
            r = m;
        } else {
            l = m;
        }
    }

    cout << r << "\n";
}
