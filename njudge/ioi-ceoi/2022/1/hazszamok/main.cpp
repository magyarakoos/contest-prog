#include <bits/stdc++.h>
using namespace std;
#define int int64_t

int32_t main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int K;
    cin >> K;
    vector<int> a(K);
    for (int& x : a) cin >> x;

    vector<int> pw(13, 1);
    for (int i = 2; i <= 12; i++) pw[i] = pw[i - 1] * K;

    auto f = [&](int n) -> bool { return 0; };

    int l = 0, r = 1e18;
    while (r - l > 1) {
        int m = (r + l) / 2;
        if (f(m)) {
            r = m;
        } else {
            l = m;
        }
    }
}
