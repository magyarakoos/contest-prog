#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using i128 = __int128;
using i64 = long long;
using i32 = int;

i32 main() {
    i128 N, M;
    i64 _n, _m;
    cin >> _n >> _m;
    N = _n;
    M = _m;

    vector<i128> T(N);
    for (i128& x : T) {
        i64 y;
        cin >> y;
        x = y;
    }
    sort(T.begin(), T.end());

    auto f = [&](i128 x) -> bool {
        i128 result = 0;
        for (int i = 0; i < N; i++) {
            if (x / T[i] > M - result) return 1;
            result += x / T[i];
        }
        return 0;
    };

    i128 l = 0, r = 1e19;
    while (r - l > 1) {
        i128 m = l + (r - l) / 2;
        if (f(m)) {
            r = m;
        } else {
            l = m;
        }
    }

    cout << (i64)r << "\n";
}

