#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

#include "debug.h"

using namespace std;
using ll = long long;

void solve() {
    vector<ll> h(52);
    int Q;
    cin >> Q;
    while (Q--) {
        ll F, K;
        char C;
        cin >> F >> C >> K;
        if (C >= 'a') {
            C -= 'a';
        } else {
            C = C - 'A' + 26;
        }

        auto nh = h;
        sort(nh.begin(), nh.end());

        for (int i = 0; i < 51; i++) {
            if (K <= nh[i]) {
                nh[51] += K;
                nh[i] -= K;
                break;
            } else {
                nh[51] += nh[i];
                K -= nh[i];
                nh[i] = 0;
            }
        }

        ll sum = accumulate(nh.begin(), nh.end(), 0LL),
           result = 0;
        for (int i = 0; i < 52; i++) {
            result += nh[i] * (sum - nh[i]);
        }
        DB(nh);

        cout << result / 2 << "\n";
    }
}

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) solve();
}
